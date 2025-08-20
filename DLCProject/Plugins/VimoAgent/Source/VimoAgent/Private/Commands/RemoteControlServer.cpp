#include "Commands/RemoteControlServer.h"

#include "IWebSocketNetworkingModule.h"
#include "Kismet/KismetSystemLibrary.h"
#include "JsonObjectConverter.h"

//----------------------------------------------------------------------//
URemoteControlServer* URemoteControlServer::spRemoteControlServerInstance = nullptr;

void URemoteControlServer::Stop()
{
	if (mpWebSocketServer)
	{
		// Unbind the event handlers
		mpWebSocketServer->OnMessage.Remove(OnMessageHandle);
		mpWebSocketServer->OnOpenConnection.Remove(OnOpenConnectionHandle);
		mpWebSocketServer->OnClosedConnection.Remove(OnClosedConnectionHandle);

		mpWebSocketServer->Stop();
		mpWebSocketServer.Reset();
	}
	
	if (mpProbe)
	{
		mpProbe.Reset();
	}
}

bool URemoteControlServer::TestConnection()
{
	if (mbIsReady)
	{
		return true;
	}
	else
	{
		bool tbConnected = mpProbe->Probe();
		if (tbConnected)
		{
			// Close the websocket connection so others can use it
			mpProbe.Reset();
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool URemoteControlServer::LaunchImpl()
{
	/*
	 * --------------- cmd websocket server ---------------
	 */
	mpWebSocketServer = MakeUnique<ViMo::CommandServers::FWebSocketServerWrapper>();
	
	OnMessageHandle = mpWebSocketServer->OnMessage.AddUObject(this, &URemoteControlServer::OnStreamerMessage);
	OnOpenConnectionHandle = mpWebSocketServer->OnOpenConnection.AddUObject(this, &URemoteControlServer::OnStreamerConnected);
	OnClosedConnectionHandle = mpWebSocketServer->OnClosedConnection.AddUObject(this, &URemoteControlServer::OnStreamerDisconnected);
	bool bLaunchedCmdServer = mpWebSocketServer->Launch(miPort);

	if (!bLaunchedCmdServer)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to launch websocket server for rc on port=%d"), miPort);
		return false;
	}
	
	/*
	 * --------------- Websocket probe ---------------
	 */
	if (mbPollUntilReady)
	{
		TArray<FString> tArrayProtocols;
		tArrayProtocols.Add(FString(TEXT("binary")));
		FURL tpStreamerURL;
		tpStreamerURL.Protocol = TEXT("ws");
		tpStreamerURL.Host = TEXT("127.0.0.1");
		tpStreamerURL.Port = miPort; 
		tpStreamerURL.Map = FString();
		UE_LOG(LogTemp, Error, TEXT("探针是否执行"));
		mpProbe = MakeUnique<ViMo::CommandServers::FWebSocketProbe>(tpStreamerURL, tArrayProtocols);
	}
	
	return true;
}

/*void URemoteControlServer::Send(FString rszMessage)
{
	if (mpWebSocketServer->Send(muConnectionId, rszMessage))
	{
		UE_LOG(LogTemp,Log,TEXT("send Success"));
	}
	else
	{
		UE_LOG(LogTemp,Log,TEXT("send failed"));
	}
	
}*/

void URemoteControlServer::OnStreamerConnected(uint16 ruConnectionId)
{
	//muConnectionId = ruConnectionId;
	UE_LOG(LogTemp, Log, TEXT("Streamer websocket connected, id=%d"), ruConnectionId);
}

void URemoteControlServer::OnStreamerDisconnected(uint16 ruConnectionId)
{
	UE_LOG(LogTemp, Log, TEXT("Streamer websocket disconnected, id=%d"), ruConnectionId);
}

void URemoteControlServer::OnStreamerMessage(uint16 ruConnectionId, TArrayView<uint8> rArrayMessage)
{
	FUTF8ToTCHAR Converted((const ANSICHAR*)rArrayMessage.GetData(), rArrayMessage.Num());
	FString tszOutString(Converted.Length(), Converted.Get());
	const FString tszMsg = tszOutString;
	UE_LOG(LogTemp, Log, TEXT("From Streamer id=%d: %s"), ruConnectionId, *tszMsg);
	
	TSharedPtr<FJsonObject> tpJsonObject;
	TSharedRef<TJsonReader<>> tpReader = TJsonReaderFactory<>::Create(tszMsg);

	if (FJsonSerializer::Deserialize(tpReader, tpJsonObject))
	{
		FString tszCommand;
		if (tpJsonObject->TryGetStringField(TEXT("command"), tszCommand))
		{
			HandleCommand(tszCommand);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid command format"));
		}
	}
}


void URemoteControlServer::HandleCommand(const FString& Command)
{
	if (!mpGameInstance)
	{
		mpGameInstance = GetWorld()->GetGameInstance();
	}
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, Command]()
		{
			if (mpGameInstance && mpGameInstance->GetWorld())
			{
				UKismetSystemLibrary::ExecuteConsoleCommand(mpGameInstance->GetWorld(), Command);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("-------Can not get world-------"));
			}
		}, TStatId(), nullptr, ENamedThreads::GameThread);
}

void URemoteControlServer::GetNumStreamers(TFunction<void(uint16)> OnNumStreamersReceived)
{
	if(mpWebSocketServer)
	{
		OnNumStreamersReceived(mpWebSocketServer->Count());
	}
	else
	{
		// Streamers websocket server went out of scope, so we can assume no streamers are connected.
		OnNumStreamersReceived(0);
	}
}

URemoteControlServer::URemoteControlServer(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Constructor logic here
}
