// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IWebSocket.h"
#include "HAL/ThreadSafeCounter.h"
#include "WebSocketsModule.h"
#include "Templates/SharedPointer.h"
#include "Engine/EngineBaseTypes.h"

namespace ViMo::CommandServers
{

	/* 
	* A utility class that tries to establish a websocket connection. 
	* Useful for testing whether servers have come online yet.
	*/
	class FWebSocketProbe
	{
	private:
		TSharedRef<IWebSocket> mpWebSocket;
		FThreadSafeBool mbShouldAttemptReconnect;

	public:
		FWebSocketProbe(FURL tUrl, TArray<FString> tArrayProtocols = TArray<FString>())
		: mpWebSocket(FWebSocketsModule::Get().CreateWebSocket(FString::Printf(TEXT("%s://%s:%d"), *(tUrl.Protocol), *(tUrl.Host), tUrl.Port), tArrayProtocols))
			, mbShouldAttemptReconnect(true)
		{
			mpWebSocket->OnConnectionError().AddLambda([tUrl, &bShouldAttemptReconnect = mbShouldAttemptReconnect](const FString& tszError) {
				UE_LOG(LogTemp, Log, TEXT("Probing websocket %s | Msg= \"%s\" | Retrying..."), *FString::Printf(TEXT("%s://%s:%d"), *(tUrl.Protocol), *(tUrl.Host), tUrl.Port),  *tszError);
				bShouldAttemptReconnect = true;
			});
		}

		bool Probe()
		{
			bool rbIsConnected = mpWebSocket->IsConnected();

			if (!rbIsConnected && mbShouldAttemptReconnect)
			{
				mpWebSocket->Connect();
				mbShouldAttemptReconnect = false;
			}

			return rbIsConnected;
		}
	};

} // UE::PixelStreamingServers
