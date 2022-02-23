// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	//steps: create c++ class
	//add , "GameplayTasks" to .Build.cs
	//recompile
	//assign NodeName
	NodeName = (TEXT("Shoot"));
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetOwner() == nullptr ) return EBTNodeResult::Failed;

	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if (Character == nullptr) return EBTNodeResult::Failed;

	Character->Shoot();
	return EBTNodeResult::Succeeded;
}