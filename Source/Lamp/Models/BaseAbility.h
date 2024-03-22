#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ENUM_AttackType.h"
#include "BaseAbility.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UBaseAbility : public UObject
{
    GENERATED_BODY()

public:
    UBaseAbility();

    //Variable que define cuántos ataques tendrá cada combo de ataque
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combo")
    int32 MaxComboAttacks;

    //Recibe el tipo de ataque que se está ejecutando (ENUM_AttackType) relacionado con la dirección en la que apunte el usuario
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AbilityComponent")
    int32 PerformAttackActions(ENUM_AttackType attackType);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AbilityComponent")
    int32 PerformTargetAttackAction(ENUM_AttackType attackType);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AbilityComponent")
    void PerformSpecialMovement();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AbilityComponent")
    void PerformAimAction();

};
