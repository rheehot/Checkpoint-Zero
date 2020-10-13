// © 2020 Seokjin Lee <seokjin.dev@gmail.com>

#include "CP0Character.h"

ACP0Character::ACP0Character()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACP0Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACP0Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACP0Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACP0Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACP0Character::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ACP0Character::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACP0Character::LookUp);
}

void ACP0Character::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector(), AxisValue);
}

void ACP0Character::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector(), AxisValue);
}

void ACP0Character::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ACP0Character::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}
