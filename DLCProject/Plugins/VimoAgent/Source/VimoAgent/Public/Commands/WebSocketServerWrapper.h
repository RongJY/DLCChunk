// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IWebSocketServer.h"
#include "Templates/UniquePtr.h"
#include "Templates/SharedPointer.h"
#include "WebSocketNetworkingDelegates.h"
#include "INetworkingWebSocket.h"
#include "Tickable.h"
#include "HAL/ThreadSafeCounter.h"
#include "Containers/ArrayView.h"
#include "HAL/ThreadSafeBool.h"

namespace ViMo::CommandServers
{

	struct FWebSocketConnection
	{
	public:
		FWebSocketConnection(INetworkingWebSocket* rpInSocketConnection);
		~FWebSocketConnection();
		uint16 GetId() const;
		TArray<FString> GetUrlArgs() const;
		bool Send(FString rszMessage) const;
		void SetCallbacks();

	public:
		FWebSocketPacketReceivedCallBack OnPacketReceivedCallback;
		FWebSocketInfoCallBack OnClosedCallback;

	private:
		static FThreadSafeCounter mpIdGenerator;
		uint16 muId;
		TArray<FString> mArrayUrlArgs;
		INetworkingWebSocket* mpSocketConnection;
	};


	class FWebSocketServerWrapper : public FTickableGameObject
	{
	public:
		FWebSocketServerWrapper();
		virtual ~FWebSocketServerWrapper();
		void EnableWebServer(TArray<FWebSocketHttpMount> rArrayInDirectoriesToServe);
		bool Launch(uint16 ruPort);
		void Stop();
		bool IsLaunched() const;
		bool HasConnections() const;
		bool Close(uint16 ruConnectionId);
		/**
		 * Send message to a particular websocket connection.
		 * Note: This message is sent as binary using the websocket protocol because of the WS implementation that is used.
		 * @return True if the message able to be sent.
		 */
		bool Send(uint16 ruConnectionId, FString rszMessage) const;
		bool Send(const FString& rszConnectionName, FString rszMessage) const;
		bool GetFirstConnection(uint16& ruOutConnectionId) const;
		TMap<uint16, TUniquePtr<FWebSocketConnection>>& GetConnections() { return mMapConnections; }

		void NameConnection(uint16 ruConnectionId, const FString& rszName);
		void RemoveName(const FString& rszName);
		bool GetNamedConnection(const FString& rszName, uint16& ruOutConnectionId) const;
		TArray<FString> GetConnectionNames() const;

		/* Begin FTickableGameObject */
		virtual bool IsTickableWhenPaused() const { return true; }
		virtual bool IsTickableInEditor() const { return true; }
		virtual void Tick(float DeltaTime) override;
		virtual bool IsAllowedToTick() const { return true; }
		TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(FWebSocketServerWrapper, STATGROUP_Tickables); }
		/* End FTickableGameObject */

		int32 Count() const { return mMapNamedConnections.Num(); }

	public:
		DECLARE_MULTICAST_DELEGATE_OneParam(FOnNewWebSocketConnection, uint16 /*Connection Id*/);
		FOnNewWebSocketConnection OnOpenConnection;

		DECLARE_MULTICAST_DELEGATE_OneParam(FOnClosedWebSocketConnection, uint16 /*Connection Id*/);
		FOnClosedWebSocketConnection OnClosedConnection;

		DECLARE_MULTICAST_DELEGATE_TwoParams(FOnMessageWebSocketConnection, uint16 /*Connection Id*/, TArrayView<uint8> /*Message*/);
		FOnMessageWebSocketConnection OnMessage;

	protected:
		virtual void OnConnectionOpened(INetworkingWebSocket* Socket);
		virtual void OnPacketReceived(void* rpData, int32 riSize, uint16 ruConnectionId);
		virtual void OnConnectionClosed(uint16 ruConnectionId);

	private:
		FThreadSafeBool mbLaunched;
		TUniquePtr<IWebSocketServer> mpWSServer;
		FWebSocketClientConnectedCallBack OnClientConnectedCallback;
		TMap<uint16, TUniquePtr<FWebSocketConnection>> mMapConnections;
		TMap<FString, uint16> mMapNamedConnections;
		bool mbEnableWebServer = false;
		TArray<FWebSocketHttpMount> mArrayDirectoriesToServe;
	};

} // UE::PixelStreamingServers
