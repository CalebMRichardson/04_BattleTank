// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ATankPlayerController BeginPlay()"));
	
	auto ControlledTank = GetControlledTank();
	
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Possed Tank: %s"), *(ControlledTank->GetName()));
	} else {
		UE_LOG(LogTemp, Error, TEXT("No possed Tank."));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

	if (!GetControlledTank()) {
		return; 
	}
	
	FVector HitLocation; // out param
	if (GetSightRayHitLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	
	}
}

// Get world location of LineTrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const {

	// convert screen coordinates to world coordinates
	// check if world coordinates hits the landscape
	// set OutHitLocation to the landscape position
	// return true
	// else
	// return false
	OutHitLocation = FVector(1.0);
	return true;
}

