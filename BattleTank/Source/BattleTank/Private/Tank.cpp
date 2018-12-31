#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = true;
	
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}