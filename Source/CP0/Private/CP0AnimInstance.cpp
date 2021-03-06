// (C) 2020 Seokjin Lee <seokjin.dev@gmail.com>

#include "CP0AnimInstance.h"
#include "CP0Character.h"
#include "CP0CharacterMovement.h"

void UCP0AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    const auto Character = CastChecked<ACP0Character>(TryGetPawnOwner(), ECastCheckedType::NullAllowed);
    if (!Character)
        return;

    const auto Velocity = Character->GetVelocity();
    MoveSpeed = Velocity.Size2D();
    MoveDirection = CalculateDirection(Velocity, Character->GetActorRotation());

    const auto AimRot = Character->GetControlRotation() - Character->GetActorRotation();
    AimPitch = FRotator::NormalizeAxis(AimRot.Pitch);
    AimYaw = FRotator::NormalizeAxis(AimRot.Yaw);
   
    const auto Movement = Character->GetCP0Movement();
    Posture = Movement->GetPosture();
    bIsOnGround = Movement->IsMovingOnGround();
    bIsSprinting = Movement->IsSprinting() && MoveSpeed > MinSprintSpeed;
    bShouldPlayPostureAnim = MoveSpeed < MaxPostureAnimWalkSpeed || Movement->IsProneSwitching();
}
