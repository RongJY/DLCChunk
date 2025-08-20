// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VimoAgent/Public/VimoAgentInstSubsys.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVimoAgentInstSubsys() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UNetDriver_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
NETCORE_API UEnum* Z_Construct_UEnum_NetCore_ENetworkFailure();
UPackage* Z_Construct_UPackage__Script_VimoAgent();
VIMOAGENT_API UClass* Z_Construct_UClass_UVimoAgentInstSubsys();
VIMOAGENT_API UClass* Z_Construct_UClass_UVimoAgentInstSubsys_NoRegister();
VIMOAGENT_API UEnum* Z_Construct_UEnum_VimoAgent_EVimoAgentEnum();
// End Cross Module References

// Begin Enum EVimoAgentEnum
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVimoAgentEnum;
static UEnum* EVimoAgentEnum_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EVimoAgentEnum.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EVimoAgentEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VimoAgent_EVimoAgentEnum, (UObject*)Z_Construct_UPackage__Script_VimoAgent(), TEXT("EVimoAgentEnum"));
	}
	return Z_Registration_Info_UEnum_EVimoAgentEnum.OuterSingleton;
}
template<> VIMOAGENT_API UEnum* StaticEnum<EVimoAgentEnum>()
{
	return EVimoAgentEnum_StaticEnum();
}
struct Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
		{ "param1.DisplayName", "param1" },
		{ "param1.Name", "param1" },
		{ "param10.DisplayName", "param10" },
		{ "param10.Name", "param10" },
		{ "param2.DisplayName", "param2" },
		{ "param2.Name", "param2" },
		{ "param3.DisplayName", "param3" },
		{ "param3.Name", "param3" },
		{ "param4.DisplayName", "param4" },
		{ "param4.Name", "param4" },
		{ "param5.DisplayName", "param5" },
		{ "param5.Name", "param5" },
		{ "param6.DisplayName", "param6" },
		{ "param6.Name", "param6" },
		{ "param7.DisplayName", "param7" },
		{ "param7.Name", "param7" },
		{ "param8.DisplayName", "param8" },
		{ "param8.Name", "param8" },
		{ "param9.DisplayName", "param9" },
		{ "param9.Name", "param9" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "param1", (int64)param1 },
		{ "param2", (int64)param2 },
		{ "param3", (int64)param3 },
		{ "param4", (int64)param4 },
		{ "param5", (int64)param5 },
		{ "param6", (int64)param6 },
		{ "param7", (int64)param7 },
		{ "param8", (int64)param8 },
		{ "param9", (int64)param9 },
		{ "param10", (int64)param10 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_VimoAgent,
	nullptr,
	"EVimoAgentEnum",
	"EVimoAgentEnum",
	Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_VimoAgent_EVimoAgentEnum()
{
	if (!Z_Registration_Info_UEnum_EVimoAgentEnum.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVimoAgentEnum.InnerSingleton, Z_Construct_UEnum_VimoAgent_EVimoAgentEnum_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EVimoAgentEnum.InnerSingleton;
}
// End Enum EVimoAgentEnum

// Begin Class UVimoAgentInstSubsys Function ConvertStringToEnum
struct Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics
{
	struct VimoAgentInstSubsys_eventConvertStringToEnum_Parms
	{
		FString rszEnumString;
		uint8 ruOutEnumValue;
		FText rErrorMessage;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utilities|Enums" },
		{ "DisplayName", "String to Param" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rszEnumString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_rszEnumString;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ruOutEnumValue;
	static const UECodeGen_Private::FTextPropertyParams NewProp_rErrorMessage;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_rszEnumString = { "rszEnumString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventConvertStringToEnum_Parms, rszEnumString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rszEnumString_MetaData), NewProp_rszEnumString_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ruOutEnumValue = { "ruOutEnumValue", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventConvertStringToEnum_Parms, ruOutEnumValue), nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_rErrorMessage = { "rErrorMessage", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventConvertStringToEnum_Parms, rErrorMessage), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((VimoAgentInstSubsys_eventConvertStringToEnum_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VimoAgentInstSubsys_eventConvertStringToEnum_Parms), &Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_rszEnumString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ruOutEnumValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_rErrorMessage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInstSubsys, nullptr, "ConvertStringToEnum", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::VimoAgentInstSubsys_eventConvertStringToEnum_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::VimoAgentInstSubsys_eventConvertStringToEnum_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVimoAgentInstSubsys::execConvertStringToEnum)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_rszEnumString);
	P_GET_PROPERTY_REF(FByteProperty,Z_Param_Out_ruOutEnumValue);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_rErrorMessage);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UVimoAgentInstSubsys::ConvertStringToEnum(Z_Param_rszEnumString,Z_Param_Out_ruOutEnumValue,Z_Param_Out_rErrorMessage);
	P_NATIVE_END;
}
// End Class UVimoAgentInstSubsys Function ConvertStringToEnum

// Begin Class UVimoAgentInstSubsys Function GetAndroidThunkCpp
struct Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics
{
	struct VimoAgentInstSubsys_eventGetAndroidThunkCpp_Parms
	{
		FString rszParam;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utilities|Enums" },
		{ "DisplayName", "Get Param" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_rszParam;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::NewProp_rszParam = { "rszParam", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventGetAndroidThunkCpp_Parms, rszParam), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventGetAndroidThunkCpp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::NewProp_rszParam,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInstSubsys, nullptr, "GetAndroidThunkCpp", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::VimoAgentInstSubsys_eventGetAndroidThunkCpp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::VimoAgentInstSubsys_eventGetAndroidThunkCpp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVimoAgentInstSubsys::execGetAndroidThunkCpp)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_rszParam);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetAndroidThunkCpp(Z_Param_rszParam);
	P_NATIVE_END;
}
// End Class UVimoAgentInstSubsys Function GetAndroidThunkCpp

// Begin Class UVimoAgentInstSubsys Function HandleCommand
struct Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics
{
	struct VimoAgentInstSubsys_eventHandleCommand_Parms
	{
		FString rszCommand;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "VimoAgent" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rszCommand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_rszCommand;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::NewProp_rszCommand = { "rszCommand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventHandleCommand_Parms, rszCommand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rszCommand_MetaData), NewProp_rszCommand_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::NewProp_rszCommand,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInstSubsys, nullptr, "HandleCommand", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::VimoAgentInstSubsys_eventHandleCommand_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::VimoAgentInstSubsys_eventHandleCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVimoAgentInstSubsys::execHandleCommand)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_rszCommand);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleCommand(Z_Param_rszCommand);
	P_NATIVE_END;
}
// End Class UVimoAgentInstSubsys Function HandleCommand

// Begin Class UVimoAgentInstSubsys Function HandleNetworkFailure
struct Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics
{
	struct VimoAgentInstSubsys_eventHandleNetworkFailure_Parms
	{
		UWorld* rpWorld;
		UNetDriver* rpNetDriver;
		TEnumAsByte<ENetworkFailure::Type> reFailureType;
		FString rszErrorString;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rszErrorString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_rpWorld;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_rpNetDriver;
	static const UECodeGen_Private::FBytePropertyParams NewProp_reFailureType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_rszErrorString;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rpWorld = { "rpWorld", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventHandleNetworkFailure_Parms, rpWorld), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rpNetDriver = { "rpNetDriver", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventHandleNetworkFailure_Parms, rpNetDriver), Z_Construct_UClass_UNetDriver_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_reFailureType = { "reFailureType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventHandleNetworkFailure_Parms, reFailureType), Z_Construct_UEnum_NetCore_ENetworkFailure, METADATA_PARAMS(0, nullptr) }; // 1270560748
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rszErrorString = { "rszErrorString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventHandleNetworkFailure_Parms, rszErrorString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rszErrorString_MetaData), NewProp_rszErrorString_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rpWorld,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rpNetDriver,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_reFailureType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::NewProp_rszErrorString,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInstSubsys, nullptr, "HandleNetworkFailure", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::VimoAgentInstSubsys_eventHandleNetworkFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::VimoAgentInstSubsys_eventHandleNetworkFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVimoAgentInstSubsys::execHandleNetworkFailure)
{
	P_GET_OBJECT(UWorld,Z_Param_rpWorld);
	P_GET_OBJECT(UNetDriver,Z_Param_rpNetDriver);
	P_GET_PROPERTY(FByteProperty,Z_Param_reFailureType);
	P_GET_PROPERTY(FStrProperty,Z_Param_rszErrorString);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleNetworkFailure(Z_Param_rpWorld,Z_Param_rpNetDriver,ENetworkFailure::Type(Z_Param_reFailureType),Z_Param_rszErrorString);
	P_NATIVE_END;
}
// End Class UVimoAgentInstSubsys Function HandleNetworkFailure

// Begin Class UVimoAgentInstSubsys Function TestStringToEnum
struct Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics
{
	struct VimoAgentInstSubsys_eventTestStringToEnum_Parms
	{
		int32 riIndex;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Utilities|Enums" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xe6\xb5\x8b\xe8\xaf\x95\xe6\x9e\x9a\xe4\xb8\xbe\xe8\xbf\x94\xe5\x9b\x9e\xe7\x9a\x84""FString\xe6\x98\xaf\xe4\xbb\x80\xe4\xb9\x88\n" },
#endif
		{ "DisplayName", "String to Test" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb5\x8b\xe8\xaf\x95\xe6\x9e\x9a\xe4\xb8\xbe\xe8\xbf\x94\xe5\x9b\x9e\xe7\x9a\x84""FString\xe6\x98\xaf\xe4\xbb\x80\xe4\xb9\x88" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_riIndex;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::NewProp_riIndex = { "riIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventTestStringToEnum_Parms, riIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInstSubsys_eventTestStringToEnum_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::NewProp_riIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInstSubsys, nullptr, "TestStringToEnum", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::VimoAgentInstSubsys_eventTestStringToEnum_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::VimoAgentInstSubsys_eventTestStringToEnum_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UVimoAgentInstSubsys::execTestStringToEnum)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_riIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UVimoAgentInstSubsys::TestStringToEnum(Z_Param_riIndex);
	P_NATIVE_END;
}
// End Class UVimoAgentInstSubsys Function TestStringToEnum

// Begin Class UVimoAgentInstSubsys
void UVimoAgentInstSubsys::StaticRegisterNativesUVimoAgentInstSubsys()
{
	UClass* Class = UVimoAgentInstSubsys::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConvertStringToEnum", &UVimoAgentInstSubsys::execConvertStringToEnum },
		{ "GetAndroidThunkCpp", &UVimoAgentInstSubsys::execGetAndroidThunkCpp },
		{ "HandleCommand", &UVimoAgentInstSubsys::execHandleCommand },
		{ "HandleNetworkFailure", &UVimoAgentInstSubsys::execHandleNetworkFailure },
		{ "TestStringToEnum", &UVimoAgentInstSubsys::execTestStringToEnum },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVimoAgentInstSubsys);
UClass* Z_Construct_UClass_UVimoAgentInstSubsys_NoRegister()
{
	return UVimoAgentInstSubsys::StaticClass();
}
struct Z_Construct_UClass_UVimoAgentInstSubsys_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "VimoAgentInstSubsys.h" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mszServerIP_MetaData[] = {
		{ "Category", "AdvancedVoiceInterface" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mszPlayerName_MetaData[] = {
		{ "Category", "AdvancedVoiceInterface" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mszAvatar_MetaData[] = {
		{ "Category", "AdvancedVoiceInterface" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_meVimoAgentEnum_MetaData[] = {
		{ "Category", "VimoAgent" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mMapVimoParam_MetaData[] = {
		{ "Category", "VimoAgent" },
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mpGameInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/VimoAgentInstSubsys.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_mszServerIP;
	static const UECodeGen_Private::FStrPropertyParams NewProp_mszPlayerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_mszAvatar;
	static const UECodeGen_Private::FBytePropertyParams NewProp_meVimoAgentEnum;
	static const UECodeGen_Private::FStrPropertyParams NewProp_mMapVimoParam_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_mMapVimoParam_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_mMapVimoParam;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mpGameInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVimoAgentInstSubsys_ConvertStringToEnum, "ConvertStringToEnum" }, // 2257029154
		{ &Z_Construct_UFunction_UVimoAgentInstSubsys_GetAndroidThunkCpp, "GetAndroidThunkCpp" }, // 3149120644
		{ &Z_Construct_UFunction_UVimoAgentInstSubsys_HandleCommand, "HandleCommand" }, // 1576092818
		{ &Z_Construct_UFunction_UVimoAgentInstSubsys_HandleNetworkFailure, "HandleNetworkFailure" }, // 2314946691
		{ &Z_Construct_UFunction_UVimoAgentInstSubsys_TestStringToEnum, "TestStringToEnum" }, // 3113410110
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVimoAgentInstSubsys>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszServerIP = { "mszServerIP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, mszServerIP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mszServerIP_MetaData), NewProp_mszServerIP_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszPlayerName = { "mszPlayerName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, mszPlayerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mszPlayerName_MetaData), NewProp_mszPlayerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszAvatar = { "mszAvatar", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, mszAvatar), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mszAvatar_MetaData), NewProp_mszAvatar_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_meVimoAgentEnum = { "meVimoAgentEnum", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, meVimoAgentEnum), Z_Construct_UEnum_VimoAgent_EVimoAgentEnum, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_meVimoAgentEnum_MetaData), NewProp_meVimoAgentEnum_MetaData) }; // 1028593318
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam_ValueProp = { "mMapVimoParam", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam_Key_KeyProp = { "mMapVimoParam_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam = { "mMapVimoParam", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, mMapVimoParam), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mMapVimoParam_MetaData), NewProp_mMapVimoParam_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mpGameInstance = { "mpGameInstance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVimoAgentInstSubsys, mpGameInstance), Z_Construct_UClass_UGameInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mpGameInstance_MetaData), NewProp_mpGameInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVimoAgentInstSubsys_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszServerIP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszPlayerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mszAvatar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_meVimoAgentEnum,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mMapVimoParam,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVimoAgentInstSubsys_Statics::NewProp_mpGameInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInstSubsys_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UVimoAgentInstSubsys_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_VimoAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInstSubsys_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UVimoAgentInstSubsys_Statics::ClassParams = {
	&UVimoAgentInstSubsys::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UVimoAgentInstSubsys_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInstSubsys_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInstSubsys_Statics::Class_MetaDataParams), Z_Construct_UClass_UVimoAgentInstSubsys_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UVimoAgentInstSubsys()
{
	if (!Z_Registration_Info_UClass_UVimoAgentInstSubsys.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVimoAgentInstSubsys.OuterSingleton, Z_Construct_UClass_UVimoAgentInstSubsys_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UVimoAgentInstSubsys.OuterSingleton;
}
template<> VIMOAGENT_API UClass* StaticClass<UVimoAgentInstSubsys>()
{
	return UVimoAgentInstSubsys::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UVimoAgentInstSubsys);
UVimoAgentInstSubsys::~UVimoAgentInstSubsys() {}
// End Class UVimoAgentInstSubsys

// Begin Registration
struct Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EVimoAgentEnum_StaticEnum, TEXT("EVimoAgentEnum"), &Z_Registration_Info_UEnum_EVimoAgentEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1028593318U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVimoAgentInstSubsys, UVimoAgentInstSubsys::StaticClass, TEXT("UVimoAgentInstSubsys"), &Z_Registration_Info_UClass_UVimoAgentInstSubsys, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVimoAgentInstSubsys), 3356053639U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_825855006(TEXT("/Script/VimoAgent"),
	Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
