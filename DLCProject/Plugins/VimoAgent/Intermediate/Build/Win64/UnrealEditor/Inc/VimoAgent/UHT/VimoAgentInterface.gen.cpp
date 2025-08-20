// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VimoAgent/Public/Commands/VimoAgentInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVimoAgentInterface() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_VimoAgent();
VIMOAGENT_API UClass* Z_Construct_UClass_UVimoAgentInterface();
VIMOAGENT_API UClass* Z_Construct_UClass_UVimoAgentInterface_NoRegister();
// End Cross Module References

// Begin Interface UVimoAgentInterface Function StartPlay
struct Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics
{
	struct VimoAgentInterface_eventStartPlay_Parms
	{
		FString Param;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Commands/VimoAgentInterface.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Param;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VimoAgentInterface_eventStartPlay_Parms, Param), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::NewProp_Param,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVimoAgentInterface, nullptr, "StartPlay", nullptr, nullptr, Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::VimoAgentInterface_eventStartPlay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020600, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::VimoAgentInterface_eventStartPlay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UVimoAgentInterface_StartPlay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVimoAgentInterface_StartPlay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IVimoAgentInterface::execStartPlay)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Param);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartPlay(Z_Param_Param);
	P_NATIVE_END;
}
// End Interface UVimoAgentInterface Function StartPlay

// Begin Interface UVimoAgentInterface
void UVimoAgentInterface::StaticRegisterNativesUVimoAgentInterface()
{
	UClass* Class = UVimoAgentInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "StartPlay", &IVimoAgentInterface::execStartPlay },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVimoAgentInterface);
UClass* Z_Construct_UClass_UVimoAgentInterface_NoRegister()
{
	return UVimoAgentInterface::StaticClass();
}
struct Z_Construct_UClass_UVimoAgentInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Commands/VimoAgentInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UVimoAgentInterface_StartPlay, "StartPlay" }, // 644009300
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IVimoAgentInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UVimoAgentInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_VimoAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UVimoAgentInterface_Statics::ClassParams = {
	&UVimoAgentInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVimoAgentInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UVimoAgentInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UVimoAgentInterface()
{
	if (!Z_Registration_Info_UClass_UVimoAgentInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVimoAgentInterface.OuterSingleton, Z_Construct_UClass_UVimoAgentInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UVimoAgentInterface.OuterSingleton;
}
template<> VIMOAGENT_API UClass* StaticClass<UVimoAgentInterface>()
{
	return UVimoAgentInterface::StaticClass();
}
UVimoAgentInterface::UVimoAgentInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UVimoAgentInterface);
UVimoAgentInterface::~UVimoAgentInterface() {}
// End Interface UVimoAgentInterface

// Begin Registration
struct Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UVimoAgentInterface, UVimoAgentInterface::StaticClass, TEXT("UVimoAgentInterface"), &Z_Registration_Info_UClass_UVimoAgentInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVimoAgentInterface), 681986961U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_1470604582(TEXT("/Script/VimoAgent"),
	Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
