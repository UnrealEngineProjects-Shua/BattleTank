// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"



void UTankMovementComponent::Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend move backward throw: %f"), Throw);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend turn left throw: %f"), Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend turn right throw: %f"), Throw);
}


