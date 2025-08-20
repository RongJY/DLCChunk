// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVimoAgent_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VimoAgent;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VimoAgent()
	{
		if (!Z_Registration_Info_UPackage__Script_VimoAgent.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VimoAgent",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x30FB844C,
				0xA792BEE0,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VimoAgent.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VimoAgent.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VimoAgent(Z_Construct_UPackage__Script_VimoAgent, TEXT("/Script/VimoAgent"), Z_Registration_Info_UPackage__Script_VimoAgent, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x30FB844C, 0xA792BEE0));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
