// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VimoAgentInstSubsys.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UNetDriver;
class UWorld;
#ifdef VIMOAGENT_VimoAgentInstSubsys_generated_h
#error "VimoAgentInstSubsys.generated.h already included, missing '#pragma once' in VimoAgentInstSubsys.h"
#endif
#define VIMOAGENT_VimoAgentInstSubsys_generated_h

#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleCommand); \
	DECLARE_FUNCTION(execTestStringToEnum); \
	DECLARE_FUNCTION(execGetAndroidThunkCpp); \
	DECLARE_FUNCTION(execConvertStringToEnum); \
	DECLARE_FUNCTION(execHandleNetworkFailure);


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVimoAgentInstSubsys(); \
	friend struct Z_Construct_UClass_UVimoAgentInstSubsys_Statics; \
public: \
	DECLARE_CLASS(UVimoAgentInstSubsys, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VimoAgent"), NO_API) \
	DECLARE_SERIALIZER(UVimoAgentInstSubsys)


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UVimoAgentInstSubsys(UVimoAgentInstSubsys&&); \
	UVimoAgentInstSubsys(const UVimoAgentInstSubsys&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVimoAgentInstSubsys); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVimoAgentInstSubsys); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVimoAgentInstSubsys) \
	NO_API virtual ~UVimoAgentInstSubsys();


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_28_PROLOG
#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_INCLASS_NO_PURE_DECLS \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VIMOAGENT_API UClass* StaticClass<class UVimoAgentInstSubsys>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_VimoAgentInstSubsys_h


#define FOREACH_ENUM_EVIMOAGENTENUM(op) \
	op(param1) \
	op(param2) \
	op(param3) \
	op(param4) \
	op(param5) \
	op(param6) \
	op(param7) \
	op(param8) \
	op(param9) \
	op(param10) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
