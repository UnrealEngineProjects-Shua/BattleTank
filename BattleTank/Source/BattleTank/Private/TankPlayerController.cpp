// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	Cast<ATank>(GetPawn());

	UE_LOG(LogTemp, Warning, TEXT("I am working"))


	return nullptr;
}

//void ATankPlayerController::BeginPlay()
//{
//	Super BeginPlay();
//
//	UE_LOG(LogTemp, Warning, TEXT("Player Begin Play"))
//}
