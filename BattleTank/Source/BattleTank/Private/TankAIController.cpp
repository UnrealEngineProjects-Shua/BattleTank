// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//Fire if ready
	if (AimingComponent->GetFiringState() == EFiringState::Locked && FiringEnabled)
	AimingComponent->Fire();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		// TODO subscribe local method to tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Tank death Received"));
	if (!ensure(GetPawn())) { return; } // TODO remove if okay
	GetPawn()->DetachFromControllerPendingDestroy();
}

