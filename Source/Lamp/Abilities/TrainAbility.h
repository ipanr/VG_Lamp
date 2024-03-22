#pragma once

#include "CoreMinimal.h"
#include "../Models/BaseAbility.h"
#include "TrainAbility.generated.h"

UCLASS(Blueprintable)
class UTrainAbility : public UBaseAbility
{
    GENERATED_BODY()

public:
    // Implementación de las funciones virtuales puras
    virtual int32 PerformAttackActions_Implementation(ENUM_AttackType attackType) override;
    virtual int32 PerformTargetAttackAction_Implementation(ENUM_AttackType attackType) override;
    virtual void PerformSpecialMovement_Implementation() override;
    virtual void PerformAimAction_Implementation() override;

    UTrainAbility()
    {
        MaxComboAttacks = 6;
    }
};
