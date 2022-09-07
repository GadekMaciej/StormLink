// Copyright Epic Games, Inc. All Rights Reserved.

#include "StormLinkGameMode.h"
#include "StormLinkCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStormLinkGameMode::AStormLinkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
