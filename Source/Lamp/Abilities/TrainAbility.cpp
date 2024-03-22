#include "TrainAbility.h"

int32 UTrainAbility::PerformAttackActions_Implementation(ENUM_AttackType attackType)
{
    UE_LOG(LogTemp, Warning, TEXT("Attack Desert swing"));

    return 0;  
}

int32 UTrainAbility::PerformTargetAttackAction_Implementation(ENUM_AttackType attackType)
{
    switch (attackType)
    {
        case ENUM_AttackType::Neutral:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Neutral"));
        break;
         case ENUM_AttackType::Stab:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Stab"));
        break;
        case ENUM_AttackType::LeftSwing:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Left Swing"));
        break;
        case ENUM_AttackType::RightSwing:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Right Swing"));
        break;
        case ENUM_AttackType::SpinAttack:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Spin Attack"));
        break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("Attack Desert Neutral"));
        break;  
    }
    

    return 0;
}

void UTrainAbility::PerformSpecialMovement_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Desert: Perform Desert Movement"));
}

void UTrainAbility::PerformAimAction_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("Desert: Perform Desert Aim"));
}