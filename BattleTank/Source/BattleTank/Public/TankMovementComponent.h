// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveBackward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);

private:
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;

	// Called from AI Controller pathfinding logic
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

};
