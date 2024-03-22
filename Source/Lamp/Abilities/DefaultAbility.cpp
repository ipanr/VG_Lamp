#include "DefaultAbility.h"

int32 UDefaultAbility::PerformAttackActions_Implementation(ENUM_AttackType attackType)
{

    UE_LOG(LogTemp, Warning, TEXT("Default neutral Swing"));

    return 0;
}

int32 UDefaultAbility::PerformTargetAttackAction_Implementation(ENUM_AttackType attackType)
{
    switch (attackType)
    {
        case ENUM_AttackType::Neutral:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Neutral"));
        break;
         case ENUM_AttackType::Stab:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Stab"));
        break;
        case ENUM_AttackType::LeftSwing:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Left Swing"));
        break;
        case ENUM_AttackType::RightSwing:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Right Swing"));
        break;
        case ENUM_AttackType::SpinAttack:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Spin Attack"));
        break;
        default:
            UE_LOG(LogTemp, Warning, TEXT("Attack Default Neutral"));
        break;    
    }

    return 0;
}

void UDefaultAbility::PerformSpecialMovement_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("DefaultTool: Perform Default Movement"));
}

void UDefaultAbility::PerformAimAction_Implementation()
{
    UE_LOG(LogTemp, Warning, TEXT("DefaultTool: Perform Default Aim"));
}