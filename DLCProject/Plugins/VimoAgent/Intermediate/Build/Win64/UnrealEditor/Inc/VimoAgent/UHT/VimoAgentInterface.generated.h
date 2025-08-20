// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Commands/VimoAgentInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIMOAGENT_VimoAgentInterface_generated_h
#error "VimoAgentInterface.generated.h already included, missing '#pragma once' in VimoAgentInterface.h"
#endif
#define VIMOAGENT_VimoAgentInterface_generated_h

#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execStartPlay);


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	VIMOAGENT_API UVimoAgentInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UVimoAgentInterface(UVimoAgentInterface&&); \
	UVimoAgentInterface(const UVimoAgentInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(VIMOAGENT_API, UVimoAgentInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVimoAgentInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVimoAgentInterface) \
	VIMOAGENT_API virtual ~UVimoAgentInterface();


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUVimoAgentInterface(); \
	friend struct Z_Construct_UClass_UVimoAgentInterface_Statics; \
public: \
	DECLARE_CLASS(UVimoAgentInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/VimoAgent"), VIMOAGENT_API) \
	DECLARE_SERIALIZER(UVimoAgentInterface)


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IVimoAgentInterface() {} \
public: \
	typedef UVimoAgentInterface UClassType; \
	typedef IVimoAgentInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_11_PROLOG
#define FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VIMOAGENT_API UClass* StaticClass<class UVimoAgentInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DLCProject_Plugins_VimoAgent_Source_VimoAgent_Public_Commands_VimoAgentInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
