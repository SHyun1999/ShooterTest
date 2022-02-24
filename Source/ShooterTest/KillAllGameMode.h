// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterTestGameModeBase.h"
#include "KillAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERTEST_API AKillAllGameMode : public AShooterTestGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
private:
	void EndGame(bool bPlayerWon);
};
