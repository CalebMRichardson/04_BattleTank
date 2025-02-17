// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

/// Forward Deceleration
class UTankBarrel; 
class UTankTurret;

// Holds barrel's properties and elevation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

private:
	UTankBarrel* Barrel = nullptr; 
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
		
};
