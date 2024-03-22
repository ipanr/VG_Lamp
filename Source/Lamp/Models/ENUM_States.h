#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

UENUM(BlueprintType)
enum class ENUM_States : uint8
{
    IdleWalkRun UMETA(DisplayName = "idle-walk-run"),
    OnAir UMETA(DisplayName = "Air"),
    OnWater UMETA(DisplayName = "Water"),
    OnLedge UMETA(DisplayName = "Ledge"),
    Targeting UMETA(DisplayName = "Targeting"),
    Train UMETA(DisplayName = "Train"),
    Test UMETA(DisplayName = "Test"),
    Crab UMETA(DisplayName = "Crab"),
    Aiming UMETA(DisplatName = "Targetting")
};