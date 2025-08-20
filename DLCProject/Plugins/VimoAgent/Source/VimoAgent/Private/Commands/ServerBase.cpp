// Copyright Epic Games, Inc. All Rights Reserved.

#include "Commands/ServerBase.h"

namespace ViMo::CommandServers
{
	bool FServerBase::Launch()
	{
		mbPollUntilReady = true;

		mbHasLaunched = LaunchImpl();
		mfPollingStartedSeconds = FPlatformTime::Seconds();
		return mbHasLaunched;
	}

	bool FServerBase::IsReady()
	{
		return mbIsReady;
	}

	bool FServerBase::IsTickableWhenPaused() const
	{
		return true;
	}

	bool FServerBase::IsTickableInEditor() const
	{
		return true;
	}

	bool FServerBase::IsAllowedToTick() const
	{
		return mbAllowedToTick;
	}

	void FServerBase::Tick(float DeltaTime)
	{
		// No need to do polling if polling is turned off
		if (!mbPollUntilReady)
		{
			return;
		}

		// No need to start polling if we have not launched or we have already concluded the server is ready.
		if (!mbHasLaunched || mbIsReady)
		{
			return;
		}

		float tfSecondsElapsedPolling = FPlatformTime::Seconds() - mfPollingStartedSeconds;
		float tfSecondsSinceReconnect = FPlatformTime::Seconds() - mfLastReconnectionTimeSeconds;

		if (tfSecondsElapsedPolling < 30.0f)
		{
			if (tfSecondsSinceReconnect < 2.0f)
			{
				return;
			}

			if (TestConnection())
			{
				UE_LOG(LogTemp, Log, TEXT("Connected to the server. Server is now ready.  - Broadcasting OnReady event..."));
				OnReady.Broadcast();
				// No need to poll anymore we are connected
				mbAllowedToTick = false;
				mbIsReady = true;
				return;
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("Polling again in another %.f seconds for server to become ready..."), 2.0f);
				mfLastReconnectionTimeSeconds = FPlatformTime::Seconds();
			}
		}
		else
		{
			// No need to poll anymore we timed out
			UE_LOG(LogTemp, Error, TEXT("Server was not ready after %.f seconds, polling timed out."), 30.0f);
			mbAllowedToTick = false;
			mbTimedOut = true;
			OnFailedToReady.Broadcast();
		}
	}

	bool FServerBase::HasLaunched()
	{
		return mbHasLaunched;
	}

	bool FServerBase::IsTimedOut()
	{
		return mbTimedOut;
	}
}
