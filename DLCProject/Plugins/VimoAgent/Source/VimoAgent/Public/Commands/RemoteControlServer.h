// RemoteControlSubsystem.h
#pragma once
#include "Tickable.h"
#include "ServerBase.h"
#include "WebSocketProbe.h"
#include "IWebSocketServer.h"
#include "WebSocketServerWrapper.h"
#include "RemoteControlServer.generated.h"

UCLASS()
class VIMOAGENT_API URemoteControlServer : public UObject, public ViMo::CommandServers::FServerBase
{
	GENERATED_BODY()
public:
	URemoteControlServer(const FObjectInitializer& ObjectInitializer);

	FORCEINLINE static URemoteControlServer& Get();

	void Init(UGameInstance* rpInGameInstance)
	{
		mpGameInstance = rpInGameInstance;
	}
	
	virtual void BeginDestroy() override;
	

	// Begin FServerBase
	virtual void Stop() override;
	virtual bool TestConnection() override;
	virtual bool LaunchImpl() override;
	virtual void GetNumStreamers(TFunction<void(uint16)> OnNumStreamersReceived) override;
	// End FServerBase

	/*UFUNCTION(BlueprintCallable)
	void Send(FString rszMessage);*/
	
	
private:
	TUniquePtr<ViMo::CommandServers::FWebSocketProbe> mpProbe;
	TUniquePtr<ViMo::CommandServers::FWebSocketServerWrapper> mpWebSocketServer;
	int32 miPort = 3000;

	//uint16 muConnectionId = -1;

	void HandleCommand(const FString& rszCommand);
	
protected:
	// event handlers
	void OnStreamerConnected(uint16 ruConnectionId);
	void OnStreamerDisconnected(uint16 ruConnectionId);
	void OnStreamerMessage(uint16 ruConnectionId, TArrayView<uint8> rArrayMessage);

private:
	FDelegateHandle OnMessageHandle;
	FDelegateHandle OnOpenConnectionHandle;
	FDelegateHandle OnClosedConnectionHandle;

	static URemoteControlServer* spRemoteControlServerInstance;

	UPROPERTY()
	UGameInstance* mpGameInstance = nullptr;
	
};


URemoteControlServer& URemoteControlServer::Get()
{
	if (!spRemoteControlServerInstance)
	{
		spRemoteControlServerInstance = NewObject<URemoteControlServer>(GEngine, URemoteControlServer::StaticClass());
		check(spRemoteControlServerInstance);
		spRemoteControlServerInstance->AddToRoot();
		return *spRemoteControlServerInstance;
	}
	else
	{
		return *spRemoteControlServerInstance;
	}
}

inline void URemoteControlServer::BeginDestroy()
{
	if (spRemoteControlServerInstance == this)
	{
		spRemoteControlServerInstance = nullptr;
	}
	Super::BeginDestroy();
}
