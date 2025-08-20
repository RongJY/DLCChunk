// Copyright Epic Games, Inc. All Rights Reserved.


#include "Commands/WebSocketServerWrapper.h"

#include "IWebSocketNetworkingModule.h"
#include "Modules/ModuleManager.h"

namespace ViMo::CommandServers
{

	/*
	* ------------- FWebSocketConnection -------------
	*/

	FThreadSafeCounter FWebSocketConnection::mpIdGenerator = FThreadSafeCounter(100);

	FWebSocketConnection::FWebSocketConnection(INetworkingWebSocket* rpInSocketConnection)
		: muId(mpIdGenerator.Increment())
		, mpSocketConnection(rpInSocketConnection)
	{
		mArrayUrlArgs = mpSocketConnection->GetUrlArgs();
	}

	FWebSocketConnection::~FWebSocketConnection()
	{
		if (mpSocketConnection)
		{
			delete mpSocketConnection;
			mpSocketConnection = nullptr;
		}
	}

	uint16 FWebSocketConnection::GetId() const
	{
		return muId;
	}

	TArray<FString> FWebSocketConnection::GetUrlArgs() const
	{
		return mArrayUrlArgs;
	}

	bool FWebSocketConnection::Send(FString rszMessage) const
	{
		// Convert FString into uint8 array.
		FTCHARToUTF8 UTF8String(*rszMessage);
		
		// Send the uint8 buffer
		// Note: Due to how this socket connection is implemented, only binary messages are supported
		return mpSocketConnection->Send((const uint8*) UTF8String.Get(), UTF8String.Length(), false);
	}

	void FWebSocketConnection::SetCallbacks()
	{
		if(mpSocketConnection)
		{
			mpSocketConnection->SetReceiveCallBack(OnPacketReceivedCallback);
			mpSocketConnection->SetSocketClosedCallBack(OnClosedCallback);
		}
	}

	/*
	* ------------- FWebSocketServerWrapper -------------
	*/

	FWebSocketServerWrapper::FWebSocketServerWrapper()
		: mbLaunched(false)
	{

	}

	FWebSocketServerWrapper::~FWebSocketServerWrapper()
	{
		Stop();
	}

	void FWebSocketServerWrapper::EnableWebServer(TArray<FWebSocketHttpMount> rArrayInDirectoriesToServe)
	{
		mbEnableWebServer = true;
		mArrayDirectoriesToServe = rArrayInDirectoriesToServe;
	}

	bool FWebSocketServerWrapper::Launch(uint16 ruPort)
	{
		mpWSServer = FModuleManager::Get().LoadModuleChecked<IWebSocketNetworkingModule>(TEXT("WebSocketNetworking")).CreateServer();
		
		if(mbEnableWebServer)
		{
			mpWSServer->EnableHTTPServer(mArrayDirectoriesToServe);
		}

		OnClientConnectedCallback.BindRaw(this, &FWebSocketServerWrapper::OnConnectionOpened);
		mbLaunched = mpWSServer->Init(ruPort, OnClientConnectedCallback, TEXT("0.0.0.0"));
		if(!mbLaunched)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to launch Websocket server at ws://127.0.0.1:%d"), ruPort);
			mpWSServer.Reset();
			OnClientConnectedCallback.Unbind();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Started Websocket server at ws://0.0.0.0:%d"), ruPort);
		}
		return mbLaunched;
	}

	bool FWebSocketServerWrapper::IsLaunched() const
	{
		return mbLaunched;
	}

	bool FWebSocketServerWrapper::HasConnections() const
	{
		return mMapConnections.Num() > 0;
	}

	bool FWebSocketServerWrapper::GetFirstConnection(uint16& ruOutConnectionId) const
	{
		if(mMapConnections.Num() > 0)
		{
			ruOutConnectionId = mMapConnections.CreateConstIterator().Key();
			return true;
		}
		return false;
	}

	void FWebSocketServerWrapper::NameConnection(uint16 ruConnectionId, const FString& rszName)
	{
		if (auto* Connection = mMapConnections.Find(ruConnectionId))
		{
			mMapNamedConnections.FindOrAdd(rszName) = ruConnectionId;
		}
	}

	void FWebSocketServerWrapper::RemoveName(const FString& rszName)
	{
		mMapNamedConnections.Remove(rszName);
	}

	bool FWebSocketServerWrapper::GetNamedConnection(const FString& rszName, uint16& ruOutConnectionId) const
	{
		if (auto* ConnectionId = mMapNamedConnections.Find(rszName))
		{
			ruOutConnectionId = *ConnectionId;
			return true;
		}
		return false;
	}

	TArray<FString> FWebSocketServerWrapper::GetConnectionNames() const
	{
		TArray<FString> Names;
		for (auto [Name, ConnectionId] : mMapNamedConnections)
		{
			Names.Add(Name);
		}
		return Names;
	}

	void FWebSocketServerWrapper::Stop()
	{
		mbLaunched = false;
		mMapConnections.Empty();
		OnClientConnectedCallback.Unbind();
		mpWSServer.Reset();
	}

	bool FWebSocketServerWrapper::Close(uint16 ruConnectionId)
	{
		for (const FString* Key = mMapNamedConnections.FindKey(ruConnectionId); Key; Key = mMapNamedConnections.FindKey(ruConnectionId))
		{
			mMapNamedConnections.Remove(*Key);
		}

		if(mMapConnections.Contains(ruConnectionId))
		{
			return mMapConnections.Remove(ruConnectionId) > 0;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not close websocket connection because there was no connection=%d."), ruConnectionId);
			return false;
		}
	}

	bool FWebSocketServerWrapper::Send(uint16 ruConnectionId, FString rszMessage) const
	{
		if(mMapConnections.Contains(ruConnectionId))
		{
			return mMapConnections[ruConnectionId]->Send(rszMessage);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Did not send websocket message because there was no connection=%d."), ruConnectionId);
			return false;
		}
	}

	bool FWebSocketServerWrapper::Send(const FString& rszConnectionName, FString rszMessage) const
	{
		if (auto* ConnectionId = mMapNamedConnections.Find(rszConnectionName))
		{
			return Send(*ConnectionId, rszMessage);
		}
		return false;
	}

	void FWebSocketServerWrapper::OnConnectionOpened(INetworkingWebSocket* Socket)
	{
		if(!Socket)
		{
			UE_LOG(LogTemp, Error, TEXT("Websocket client connected with a null socket."));
			return;
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Websocket client connected. Remote=%s | Local=%s"), *Socket->RemoteEndPoint(true), *Socket->LocalEndPoint(true));
		}

		// Had a new client connect over websocket, store the connection with a unique ID.
		TUniquePtr<FWebSocketConnection> Connection = MakeUnique<FWebSocketConnection>(Socket);
		const uint16 Id = Connection->GetId();

		// Bind to socket callbacks for messages/closed.
		Connection->OnPacketReceivedCallback.BindRaw(this, &FWebSocketServerWrapper::OnPacketReceived, Id);
		Connection->OnClosedCallback.BindRaw(this, &FWebSocketServerWrapper::OnConnectionClosed, Id);
		Connection->SetCallbacks();

		mMapConnections.Add(Id, MoveTemp(Connection));

		// Broadcast that we got a new websocket connection
		OnOpenConnection.Broadcast(Id);
	}

	void FWebSocketServerWrapper::OnPacketReceived(void* rpData, int32 riSize, uint16 ruConnectionId)
	{
		if(riSize > 0)
		{
			TArrayView<uint8> DataView = MakeArrayView(static_cast<uint8*>(rpData), riSize);
			OnMessage.Broadcast(ruConnectionId, DataView);
		}
	}

	void FWebSocketServerWrapper::OnConnectionClosed(uint16 ruConnectionId)
	{
		for (const FString* Key = mMapNamedConnections.FindKey(ruConnectionId); Key; Key = mMapNamedConnections.FindKey(ruConnectionId))
		{
			mMapNamedConnections.Remove(*Key);
		}

		mMapConnections.Remove(ruConnectionId);
		OnClosedConnection.Broadcast(ruConnectionId);
	}

	void FWebSocketServerWrapper::Tick(float DeltaTime)
	{
		if(!IsLaunched())
		{
			return;
		}

		if(mpWSServer)
		{
			// Tick the websocket server
			mpWSServer->Tick();
		}
	}

} // UE::PixelStreamingServers
