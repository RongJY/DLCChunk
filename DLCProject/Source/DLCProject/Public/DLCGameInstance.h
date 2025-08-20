// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DLCGameInstance.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPatchCompleteDelegate, bool, Succeeded);
 

/**
 * 
 */
UCLASS()
class DLCPROJECT_API UDLCGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	
	virtual void Init() override;

	virtual void Shutdown() override;

	UDLCGameInstance();

	~UDLCGameInstance();

protected:
	//跟踪我们本地清单文件是否与我们网站上托管的清单文件是最新的
	bool bIsDownloadManifestUpToDate;

	//下载过程中调用的
	void OnManifestUpdateComplete(bool bSuccess);

public:
	UFUNCTION(BlueprintPure, Category = "Patching|Stats")
	void GetLoadingProgress(int64& BytesDownloaded, int64& TotalBytesToDownload, float& DownloadPercent, int32& ChunksMounted, int32& TotalChunksToMount, float& MountPercent) const;

	//修补成功或者失败时调用
	UPROPERTY(BlueprintAssignable, Category = "Patching|Stats")
	FPatchCompleteDelegate OnPatchComplete;

	// 启动游戏修补过程。如果修补清单不是最新的，则返回 false
	UFUNCTION(BlueprintCallable, Category = "Patching")
	bool PatchGame();

protected:
	// 要下载的chunk ID 列表
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Patching")
	TArray<int32> ChunkDownloadList;

	// 下载完成时调用
	void OnDownloadComplete(bool bSuccess);

	// Chunk 加载完成时调用
	void OnLoadingModeComplete(bool bSuccess);

	// 当ChunkDownLoader 完成挂载块时候调用
	void OnMountComplete(bool bSuccess);
 

	
};

