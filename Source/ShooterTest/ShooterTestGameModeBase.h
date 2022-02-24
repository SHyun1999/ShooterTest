// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERTEST_API AShooterTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled);
	
};
