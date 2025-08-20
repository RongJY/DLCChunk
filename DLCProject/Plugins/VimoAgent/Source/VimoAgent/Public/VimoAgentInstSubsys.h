// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VimoAgentInstSubsys.generated.h"

UENUM(BlueprintType)
enum EVimoAgentEnum
{
	param1			UMETA(DisplayName = "param1"),
	param2          UMETA(DisplayName = "param2"),
	param3          UMETA(DisplayName = "param3"),
	param4          UMETA(DisplayName = "param4"),
	param5          UMETA(DisplayName = "param5"),
	param6          UMETA(DisplayName = "param6"),
	param7          UMETA(DisplayName = "param7"),
	param8          UMETA(DisplayName = "param8"),
	param9          UMETA(DisplayName = "param9"),
	param10         UMETA(DisplayName = "param10"),
};


/**
 * 
 */
UCLASS()
class VIMOAGENT_API UVimoAgentInstSubsys : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UVimoAgentInstSubsys();

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION()
	void HandleNetworkFailure(UWorld* rpWorld, UNetDriver* rpNetDriver, ENetworkFailure::Type reFailureType, const FString& rszErrorString);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedVoiceInterface)
	FString mszServerIP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedVoiceInterface)
	FString mszPlayerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AdvancedVoiceInterface)
	FString mszAvatar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VimoAgent")
	TEnumAsByte<EVimoAgentEnum> meVimoAgentEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VimoAgent")
	TMap<int32,FString> mMapVimoParam;

	/*UFUNCTION(BlueprintCallable, Category = "VimoAgent")
	void Send(FString rszMessage);*/

protected:
	void ParsePlayerConfig();

	void InitVimoParamMap();

public:
	UFUNCTION(BlueprintCallable, Category = "Utilities|Enums", meta = (DisplayName = "String to Param"),BlueprintPure)
	static bool ConvertStringToEnum(
		const FString& rszEnumString,
		uint8& ruOutEnumValue,
		FText& rErrorMessage
	);

	UFUNCTION(BlueprintCallable, Category = "Utilities|Enums", meta = (DisplayName = "Get Param"),BlueprintPure)
	FString GetAndroidThunkCpp(FString rszParam);
	
	// 测试枚举返回的FString是什么
	UFUNCTION(BlueprintCallable, Category = "Utilities|Enums", meta = (DisplayName = "String to Test"),BlueprintPure)
	static FString TestStringToEnum(int32 riIndex);

	UFUNCTION(BlueprintCallable, Category = "VimoAgent")
	void HandleCommand(const FString& rszCommand);
	

	UPROPERTY()
	UGameInstance* mpGameInstance = nullptr;
	
};
