// Fill out your copyright notice in the Description page of Project Settings.


#include "KillAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!AIController->IsDead()) return;
    }
    EndGame(true);
}

void AKillAllGameMode::EndGame(bool bPlayerWon)
{
    
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        bool bIsWinner = Controller->IsPlayerController() == bPlayerWon;
        Controller->GameHasEnded(Controller->GetPawn(), bIsWinner); //false->lose, true->win
    }
}