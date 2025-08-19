// Copyright Epic Games, Inc. All Rights Reserved.

#include "DLCProjectGameMode.h"
#include "DLCProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADLCProjectGameMode::ADLCProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
