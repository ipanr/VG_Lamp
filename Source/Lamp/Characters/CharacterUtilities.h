#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Models/ENUM_AttackType.h"
#include "CharacterUtilities.generated.h"

UCLASS()
class UCharacterUtilities : public UObject
{
    GENERATED_BODY()

public:
    UCharacterUtilities();

    UFUNCTION(BlueprintCallable, Category = "Character Utilities")
    static ENUM_AttackType DetermineInputDirectionForAttacks(float directionX, float directionY);
    
};
