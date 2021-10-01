// Copyright Epic Games, Inc. All Rights Reserved.

#include "rogliekGameMode.h"
#include "rogliekPlayerController.h"
#include "rogliekCharacter.h"
#include "UObject/ConstructorHelpers.h"

ArogliekGameMode::ArogliekGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ArogliekPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}