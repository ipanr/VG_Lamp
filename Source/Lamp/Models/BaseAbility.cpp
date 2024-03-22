#include "BaseAbility.h"

UBaseAbility::UBaseAbility()
{
    // Constructor
}

int32 UBaseAbility::PerformAttackActions_Implementation(ENUM_AttackType attackType)
{
    return 0;
}

int32 UBaseAbility::PerformTargetAttackAction_Implementation(ENUM_AttackType attackType)
{
    return 0;
}


void UBaseAbility::PerformSpecialMovement_Implementation()
{
    // Implementación del movimiento especial
}

void UBaseAbility::PerformAimAction_Implementation()
{
    // Implementación de la acción de apuntar
}
