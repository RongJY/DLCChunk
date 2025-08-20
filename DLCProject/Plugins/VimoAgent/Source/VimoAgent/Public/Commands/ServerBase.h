// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Tickable.h"

namespace ViMo::CommandServers
{

	DECLARE_MULTICAST_DELEGATE(FOnReady);
	// ---------------------------------------------------------------------------------------------

	/**
	 * Interface for all Pixel Streaming servers.
	 **/
	class VIMOAGENT_API IServer
	{
	public:
		virtual ~IServer() = default;

		/* Immediately stops the server. */
		virtual void Stop() = 0;

		/**
		 * @return	True if the server has been launched. Note: Launched does not necessarily mean it is connectible yet. Bind to OnReady for that.
		 **/
		virtual bool HasLaunched() = 0;

		/**
		 * Launch the server in a child process using the supplied launch arguments.
		 * @return True if the server was able to start launching, this can fail when launching child process servers where files must exist on disk.
		 **/
		virtual bool Launch() = 0;

		/**
		 * @return	True if the server has been connected to and is ready for new connections.
		 **/
		virtual bool IsReady() = 0;

		/**
		 * @return	True if the server has timed out while trying to establish a connection.
		 **/
		virtual bool IsTimedOut() = 0;

		/**
		 * Asynchronously queries the numbers of streamers connected to the signalling server.
		 * @param OnNumStreamersReceived	Callback fired when the query for the number of streamers returns.
		*/
		virtual void GetNumStreamers(TFunction<void(uint16)> OnNumStreamersReceived) = 0;

	public:
		// Delegate fired when the server is ready for connections, first parameter is a map of all supported endpoints and their urls.
		FOnReady OnReady;

		DECLARE_MULTICAST_DELEGATE(FOnFailedToReady);
		/* Can fire when the server is unable to be contacted or connecting to it timed out. */
		FOnFailedToReady OnFailedToReady;
	};

	// Base class for all servers, provides functionality for servers to be polled for readiness while they start up.
	class FServerBase : public IServer, public FTickableGameObject
	{

	public:
		virtual ~FServerBase() = default;

		/* Begin IServer */
		virtual void Stop() = 0;
		virtual bool HasLaunched() override;
		virtual bool Launch() override;
		virtual bool IsReady() override;
		virtual bool IsTimedOut() override;
		virtual void GetNumStreamers(TFunction<void(uint16)> OnNumStreamersReceived) = 0;
		/* End IServer */

		/* Begin FTickableGameObject */
		virtual bool IsTickableWhenPaused() const override;
		virtual bool IsTickableInEditor() const override;
		virtual void Tick(float DeltaTime) override;
		virtual bool IsAllowedToTick() const override;
		TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(PixelStreamingServers, STATGROUP_Tickables); }
		/* End FTickableGameObject */

	protected:
		/**
		 * Implemented by derived types. Implementation specific but somehow the server has been tested to see if it ready for connections.
		 * @return	True if the server is able to be connected to.
		 **/
		virtual bool TestConnection() = 0;

		/**
		 * Implemented by derived types. The actual implementation of how this specified server is launched.
		 * @return True if the server was able to launch.
		 **/
		virtual bool LaunchImpl() = 0;

	protected:
		bool mbHasLaunched = false;
		FThreadSafeBool mbIsReady = false;
		float mfPollingStartedSeconds = 0.0f;
		float mfLastReconnectionTimeSeconds = 0.0f;
		bool mbAllowedToTick = true;
		bool mbTimedOut = false;
		bool mbPollUntilReady = false;

	};

} // UE::PixelStreamingServers
