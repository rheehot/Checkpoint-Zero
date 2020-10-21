// (C) 2020 Seokjin Lee <seokjin.dev@gmail.com>

#include "CP0CharacterMovement.h"
#include "BindInputAction.h"

struct FSprintAction
{
    void Enable(UCP0CharacterMovement* Movement) const
    {
    }

    void Disable(UCP0CharacterMovement* Movement) const
    {
    }

    void Toggle(UCP0CharacterMovement* Movement) const
    {
    }
};

void UCP0CharacterMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    BindInputAction(PlayerInputComponent, TEXT("Sprint"), this, FSprintAction{});
}
