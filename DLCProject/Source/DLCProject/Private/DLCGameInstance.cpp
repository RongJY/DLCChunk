// Fill out your copyright notice in the Description page of Project Settings.


#include "DLCProject/Public/DLCGameInstance.h"
#include "ChunkDownloader.h"
#include "Misc/CoreDelegates.h"


void UDLCGameInstance::Init()
{
	Super::Init();


	
	const FString DeploymentName = "DLCDemoLive";
	const FString ContentBuildId = "DLCContent";

	
	// initialize the chunk downloader with chosen platform
	TSharedRef<FChunkDownloader> Downloader = FChunkDownloader::GetOrCreate();
#if PLATFORM_WINDOWS
	Downloader->Initialize("Windows",8);
#elif PLATFORM_ANDROID
	Downloader->Initialize("Android", 8);
#endif
	// load the cached build ID
	Downloader->LoadCachedBuild(DeploymentName);

	// update the build manifest file
	TFunction<void(bool bSuccess)> UpdateCompleteCallback = [&](bool bSuccess) {bIsDownloadManifestUpToDate = true; };
	Downloader->UpdateBuild(DeploymentName, ContentBuildId, UpdateCompleteCallback);

}

void UDLCGameInstance::Shutdown()
{
	Super::Shutdown();
#if !WITH_EDITOR && !UE_SERVER	
	// 关闭下载器
	FChunkDownloader::Shutdown();
#endif
	
}

UDLCGameInstance::UDLCGameInstance()
{
	
}

UDLCGameInstance::~UDLCGameInstance()
{
	
}

void UDLCGameInstance::OnManifestUpdateComplete(bool bSuccess)
{
	bIsDownloadManifestUpToDate = bSuccess;
}

void UDLCGameInstance::GetLoadingProgress(int64& BytesDownloaded, int64& TotalBytesToDownload,
	float& DownloadPercent, int32& ChunksMounted, int32& TotalChunksToMount, float& MountPercent) const
{
	TSharedRef<FChunkDownloader> Downloader = FChunkDownloader::GetChecked();

	//获取加载统计结构
	FChunkDownloader::FStats LoadingStats = Downloader->GetLoadingStats();

	//获取下载的字节数和要下载的字节数
	BytesDownloaded = LoadingStats.BytesDownloaded;
	TotalBytesToDownload = LoadingStats.TotalBytesToDownload;

	//获取挂载的块数和要下载的块数
	ChunksMounted = LoadingStats.ChunksMounted;
	TotalChunksToMount = LoadingStats.TotalChunksToMount;

	//使用上述统计数据计算下载和挂载百分比
	if (TotalBytesToDownload != 0)
		DownloadPercent = ((float)BytesDownloaded / (float)TotalBytesToDownload) * 100.0f;
	else
		DownloadPercent = 0.0f;
	
	if (TotalChunksToMount != 0)
		MountPercent = ((float)ChunksMounted / (float)TotalChunksToMount) * 100.0f;
	else
		MountPercent = 0.0f;
}

bool UDLCGameInstance::PatchGame()
{

	// 确保下载清单是最新的
	if (bIsDownloadManifestUpToDate)
	{
		// get the chunk downloader
		TSharedRef<FChunkDownloader> Downloader = FChunkDownloader::GetChecked();

		// 报告当前块状态
		for (int32 ChunkID : ChunkDownloadList)
		{
			int32 ChunkStatus = static_cast<int32>(Downloader->GetChunkStatus(ChunkID));
			UE_LOG(LogTemp, Display, TEXT("Chunk %i status: %i"), ChunkID, ChunkStatus);
		}

		TFunction<void(bool bSuccess)> DownloadCompleteCallback = [&](bool bSuccess) {OnDownloadComplete(bSuccess); };
		Downloader->DownloadChunks(ChunkDownloadList, DownloadCompleteCallback, 1);

		// 启动加载模式
		TFunction<void(bool bSuccess)> LoadingModeCompleteCallback = [&](bool bSuccess) {OnLoadingModeComplete(bSuccess); };
		Downloader->BeginLoadingMode(LoadingModeCompleteCallback);
		return true;
	}

	// 无法联系服务器来验证清单，因此无法修补
	UE_LOG(LogTemp, Display, TEXT("Manifest Update Failed. Can't patch the game"));
	
	return false;
}

void UDLCGameInstance::OnDownloadComplete(bool bSuccess)
{
	if (bSuccess)
	{
		UE_LOG(LogTemp, Display, TEXT("Download complete"));

		// get the chunk downloader
		TSharedRef<FChunkDownloader> Downloader = FChunkDownloader::GetChecked();
		FJsonSerializableArrayInt DownloadedChunks;

		for (int32 ChunkID : ChunkDownloadList)
		{
			DownloadedChunks.Add(ChunkID);
		}

		//Mount the chunks
		TFunction<void(bool bSuccess)> MountCompleteCallback = [&](bool bSuccess) {OnMountComplete(bSuccess); };
		Downloader->MountChunks(DownloadedChunks, MountCompleteCallback);
		
		
		OnPatchComplete.Broadcast(true);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Load process failed"));

		// call the delegate
		OnPatchComplete.Broadcast(false);
	}
}

void UDLCGameInstance::OnLoadingModeComplete(bool bSuccess)
{

	OnDownloadComplete(bSuccess);

}

void UDLCGameInstance::OnMountComplete(bool bSuccess)
{

	OnPatchComplete.Broadcast(bSuccess);

}

