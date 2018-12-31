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
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	
	}
}

// Get world location of LineTrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const {

	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY; 
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector CameraWorldLocation; 
	FVector LookDirection; 

	if (GetLookDirection(ScreenLocation, LookDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString()); 
	}

	// "Deproject" the screen position of the crosshair to a world direction
	// Line-Trace along that look direction, and see what we hit ( up to a max range )
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	
	FVector CameraWorldLocation; // To be discarded

	return DeprojectScreenPositionToWorld(ScreenLocation.X, 
			ScreenLocation.Y, 
			CameraWorldLocation, 
			LookDirection); 
}
