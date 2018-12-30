// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Player conroller BeginPlay()"));
	
	auto controlledTank = GetControlledTank();
	
	if (controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Possed Tank: %s"), *(controlledTank->GetName()));
	} else {
		UE_LOG(LogTemp, Error, TEXT("No possed Tank."));
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	
	return Cast<ATank>(GetPawn());
}
