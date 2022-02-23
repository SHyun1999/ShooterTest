// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn=Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;

	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	FVector Loc;
	FRotator Rot;
	OwnerController->GetPlayerViewPoint(Loc,Rot);//these are out params

	FVector End = Loc + Rot.Vector() * MaxRange;
	// TODO: LineTrace
	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit,
														Loc, 
														End,
														ECollisionChannel::ECC_GameTraceChannel1,
														Params); // check defaultengine.ini file to get bullet collision channel
	if (bSuccess)
	{
		FVector ShotDirection = -Rot.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),
			ImpactEffect,
			Hit.Location,
			ShotDirection.Rotation());

		if (Hit.GetActor()) {
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			Hit.GetActor()->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}

}