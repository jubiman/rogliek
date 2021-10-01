// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "rogliekPlayerController.generated.h"

UCLASS()
class ArogliekPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ArogliekPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Movement functions. */
	void MoveForward(float);
	void MoveRight(float);
};


