// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"


UCLASS()
class SHOOTERTEST_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
private:
	float RestartDelay = 3.f;
	FTimerHandle RestartTimer;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget>LoseScreenClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget>WinScreenClass;
};
