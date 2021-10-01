// Copyright Epic Games, Inc. All Rights Reserved.

#include "rogliekPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "rogliekCharacter.h"
#include "Engine/World.h"

ArogliekPlayerController::ArogliekPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ArogliekPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void ArogliekPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Movement (WASD)
	InputComponent->BindAxis("MoveForward", this, &ArogliekPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ArogliekPlayerController::MoveRight);
}


// Movement funcs
void ArogliekPlayerController::MoveForward(float AxisValue)
{
	APawn* const pawn = GetPawn();
	if ((pawn != nullptr) && AxisValue != 0.0f) pawn->AddMovementInput(FVector(1.0f, 0.0f, 0.0f), AxisValue);
}

void ArogliekPlayerController::MoveRight(float AxisValue)
{
	APawn* const pawn = GetPawn();
	if ((pawn != nullptr) && AxisValue != 0.0f) pawn->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue);
}