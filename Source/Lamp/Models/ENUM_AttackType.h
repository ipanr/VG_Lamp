#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class ENUM_AttackType : uint8
{
    Neutral UMETA(DisplayName = "Neutral Attack"),
    Stab UMETA(DisplayName = "Stab"),
    LeftSwing UMETA(DisplayName = "LeftSwing"),
    RightSwing UMETA(DisplayName = "RightSwing"),
    SpinAttack UMETA(DisplayName = "SpinAttack")
};