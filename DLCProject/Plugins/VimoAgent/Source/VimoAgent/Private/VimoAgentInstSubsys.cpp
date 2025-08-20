// Fill out your copyright notice in the Description page of Project Settings.


#include "VimoAgentInstSubsys.h"

#include "Commandlets/Commandlet.h"
#include "Commands/RemoteControlServer.h"
#include "Kismet/KismetSystemLibrary.h"

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
#include "Runtime/Launch/Public/Android/AndroidJNI.h"
extern FString AndroidThunkCpp_GetIntentExtrasString(const FString& Key);
#endif
#endif



UVimoAgentInstSubsys::UVimoAgentInstSubsys()
{
	mszServerIP = "127.0.0.1";
	mszPlayerName = "player";
	mszAvatar = "0";
}

bool UVimoAgentInstSubsys::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);
	return true;
}

void UVimoAgentInstSubsys::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	InitVimoParamMap();
	ParsePlayerConfig();

	GetGameInstance()->GetEngine()->OnNetworkFailure().AddUObject(this, &UVimoAgentInstSubsys::HandleNetworkFailure);
	URemoteControlServer::Get().Init(GetGameInstance());
	URemoteControlServer::Get().LaunchImpl();
}

void UVimoAgentInstSubsys::Deinitialize()
{
	Super::Deinitialize();
	URemoteControlServer::Get().Stop();
}

void UVimoAgentInstSubsys::HandleNetworkFailure(UWorld* rpWorld, UNetDriver* rpNetDriver, ENetworkFailure::Type reFailureType, const FString& rszErrorString)
{
	if (reFailureType == ENetworkFailure::ConnectionLost || reFailureType == ENetworkFailure::ConnectionTimeout)
	{
		UE_LOG(LogTemp, Warning, TEXT("Connection with server lost: %s"), *rszErrorString);
	}
}

/*void UVimoAgentInstSubsys::Send(FString rszMessage)
{
	URemoteControlServer::Get().Send(rszMessage);
}*/

void UVimoAgentInstSubsys::ParsePlayerConfig()
{
	FString PlatformName = FPlatformProperties::PlatformName();
	{
		if (PlatformName == TEXT("Windows"))
		{
			const TCHAR* CmdLine = FCommandLine::Get();
			UE_LOG(LogTemp, Log, TEXT("ParsePlayerConfig Cmd Line : %s"), CmdLine);
			
			TArray<FString> Tokens;
			TArray<FString> Switches;
			TMap<FString, FString> Params;
			UCommandlet::ParseCommandLine(CmdLine, Tokens, Switches, Params);

			if (Params.Contains(TEXT("PlayerName")))
			{
				mszPlayerName = Params[TEXT("PlayerName")];
			}
			else
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("PlayerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("PlayerConfig"), TEXT("PlayerName"), mszPlayerName, GGameIni);
					}
				}
			}
			if (Params.Contains(TEXT("Avatar")))
			{
				mszAvatar = Params[TEXT("Avatar")];
			}
			else
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("PlayerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("PlayerConfig"), TEXT("Avatar"), mszAvatar, GGameIni);
					}
				}
			}
			if (Params.Contains(TEXT("ServerIP")))
			{
				mszServerIP = Params[TEXT("ServerIP")];
			}
			else
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("ServerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("ServerConfig"), TEXT("IP"), mszServerIP, GGameIni);
					}
				}
			}
		}
		else if (PlatformName == TEXT("Android"))
		{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			mMapVimoParam[0] = AndroidThunkCpp_GetIntentExtrasString(TEXT("PlayerName"));
			if (mszPlayerName.IsEmpty())
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("PlayerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("PlayerConfig"), TEXT("PlayerName"), mszPlayerName, GGameIni);
					}
				}
			}
			mMapVimoParam[1] = AndroidThunkCpp_GetIntentExtrasString(TEXT("Avatar"));
			if (mszAvatar.IsEmpty())
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("PlayerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("PlayerConfig"), TEXT("Avatar"), mszAvatar, GGameIni);
					}
				}
			}
			mMapVimoParam[2] = AndroidThunkCpp_GetIntentExtrasString(TEXT("ServerIP"));
			if (mszServerIP.IsEmpty())
			{
				if (GConfig)
				{
					if (GConfig->DoesSectionExist(TEXT("ServerConfig"), GGameIni))
					{
						GConfig->GetString(TEXT("ServerConfig"), TEXT("IP"), mszServerIP, GGameIni);
					}
				}
			}
			UEnum* teEnumClass = StaticEnum<EVimoAgentEnum>();
	
			for (int32 i = 3; i < mMapVimoParam.Num(); i++)
			{
				UE_LOG(LogTemp,Warning,TEXT("%s"),*teEnumClass->GetNameByValue(i).ToString());
				mMapVimoParam[i] = AndroidThunkCpp_GetIntentExtrasString(teEnumClass->GetNameByValue(i).ToString());
				
			}
#endif
		}
	}
}

void UVimoAgentInstSubsys::InitVimoParamMap()
{
	UEnum* teEnumClass = StaticEnum<EVimoAgentEnum>();
	mMapVimoParam.Add(0,"player");
	mMapVimoParam.Add(1,"0");
	mMapVimoParam.Add(2,"127.0.0.1");
	
	for (int32 i = 3; i < teEnumClass->NumEnums()-1; i++)
	{
		mMapVimoParam.Add(i,"");
	}
	
}

bool UVimoAgentInstSubsys::ConvertStringToEnum(
		const FString& rszEnumString,
		uint8& ruOutEnumValue,
		FText& rErrorMessage)
{
	UEnum* teEnumClass = StaticEnum<EVimoAgentEnum>();
	if (!teEnumClass)
	{
		rErrorMessage = FText::FromString("Invalid Enum Class");
		return false;
	}

	const int64 tiValue = teEnumClass->GetValueByNameString(rszEnumString);
	if (tiValue == INDEX_NONE)
	{
		rErrorMessage = FText::Format(
			FText::FromString("'{0}' is not a valid value for {1}"),
			FText::FromString(rszEnumString),
			FText::FromString(teEnumClass->GetName())
		);
		return false;
	}

	ruOutEnumValue = static_cast<uint8>(tiValue);
	rErrorMessage = FText::GetEmpty();
	return true;
}

FString UVimoAgentInstSubsys::GetAndroidThunkCpp(FString rszParam)
{
	uint8 tuOutEnumValue = -1;
	FText tErrorMessage = FText::FromString("");
	if (ConvertStringToEnum(rszParam, tuOutEnumValue, tErrorMessage))
	{
		return *mMapVimoParam.Find(tuOutEnumValue);
	}
	return "";
}

FString UVimoAgentInstSubsys::TestStringToEnum(int32 riIndex)
{
	UEnum* teEnumClass = StaticEnum<EVimoAgentEnum>();
	return teEnumClass->GetNameByValue(riIndex).ToString();
}

void UVimoAgentInstSubsys::HandleCommand(const FString& rszCommand)
{
	mpGameInstance = GetWorld()->GetGameInstance();
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, rszCommand]()
		{
			if (mpGameInstance && mpGameInstance->GetWorld())
			{
				UKismetSystemLibrary::ExecuteConsoleCommand(mpGameInstance->GetWorld(), rszCommand);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("-------Can not get world-------"));
			}
		}, TStatId(), nullptr, ENamedThreads::GameThread);
}

