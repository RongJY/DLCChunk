// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VimoAgent/Public/Commands/RemoteControlServer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRemoteControlServer() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_VimoAgent();
VIMOAGENT_API UClass* Z_Construct_UClass_URemoteControlServer();
VIMOAGENT_API UClass* Z_Construct_UClass_URemoteControlServer_NoRegister();
// End Cross Module References

// Begin Class URemoteControlServer
void URemoteControlServer::StaticRegisterNativesURemoteControlServer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URemoteControlServer);
UClass* Z_Construct_UClass_URemoteControlServer_NoRegister()
{
	return URemoteControlServer::StaticClass();
}
struct Z_Construct_UClass_URemoteControlServer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Commands/RemoteControlServer.h" },
		{ "ModuleRelativePath", "Public/Commands/RemoteControlServer.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mpGameInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Commands/RemoteControlServer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mpGameInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URemoteControlServer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URemoteControlServer_Statics::NewProp_mpGameInstance = { "mpGameInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URemoteControlServer, mpGameInstance), Z_Construct_UClass_UGameInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mpGameInstance_MetaData), NewProp_mpGameInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URemoteControlServer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URemoteControlServer_Statics::NewProp_mpGameInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URemoteControlServer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_URemoteControlServer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_VimoAgent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URemoteControlServer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URemoteControlServer_Statics::ClassParams = {
	&URemoteControlServer::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_URemoteControlServer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_URemoteControlServer_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URemoteControlServer_Statics::Class_MetaDataParams), Z_Construct_UClass_URemoteControlServer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URemoteControlServer()
{
	if (!Z_Registration_Info_UClass_URemoteControlServer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URemoteControlServer.OuterSingleton, Z_Construct_UClass_URemoteControlServer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URemoteControlServer.OuterSingleton;
}
template<> VIMOAGENT_API UClass* StaticClass<URemoteControlServer>()
{
	return URemoteControlServer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(URemoteControlServer);
URemoteControlServer::~URemoteControlServer() {}
// End Class URemoteControlServer

// Begin Registration
struct Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_RemoteControlServer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URemoteControlServer, URemoteControlServer::StaticClass, TEXT("URemoteControlServer"), &Z_Registration_Info_UClass_URemoteControlServer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URemoteControlServer), 2688969979U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_RemoteControlServer_h_1910880410(TEXT("/Script/VimoAgent"),
	Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_RemoteControlServer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_RemoteControlServer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
