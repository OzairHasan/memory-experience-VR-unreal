// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "lightsGameMode.h"
#include "lightsHUD.h"
#include "lightsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AlightsGameMode::AlightsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AlightsHUD::StaticClass();
}
