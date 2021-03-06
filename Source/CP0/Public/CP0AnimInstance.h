// (C) 2020 Seokjin Lee <seokjin.dev@gmail.com>

#pragma once

#include "Animation/AnimInstance.h"
#include "CP0.h"
#include "CP0AnimInstance.generated.h"

/**
 *
 */
UCLASS()
class CP0_API UCP0AnimInstance : public UAnimInstance
{
    GENERATED_BODY()

  public:
    void NativeUpdateAnimation(float DeltaSeconds) override;

  private:
    UPROPERTY(EditAnywhere, meta = (UIMin = 0))
    float MinSprintSpeed = 400.f;

    UPROPERTY(EditAnywhere, meta = (UIMin = 0))
    float MaxPostureAnimWalkSpeed = 100.f;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true, UIMin = 0))
    float MoveSpeed = 0.f;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly,
              meta = (AllowPrivateAccess = true, UIMin = -180, UIMax = 180))
    float MoveDirection = 0.f;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    float AimPitch = 0.f;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    float AimYaw = 0.f;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    EPosture Posture = EPosture::Stand;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    bool bIsSprinting = false;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    bool bIsOnGround = true;

    UPROPERTY(EditInstanceOnly, Transient, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
    bool bShouldPlayPostureAnim = true;
};
