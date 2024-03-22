#include "CharacterUtilities.h"

UCharacterUtilities::UCharacterUtilities()
{
}

ENUM_AttackType UCharacterUtilities::DetermineInputDirectionForAttacks(float directionX, float directionY)
{
    ENUM_AttackType attackTipe = ENUM_AttackType::Neutral;

    if (directionX != 0 || directionY != 0) 
    {
        if(directionX != 0)
        {
            if(directionX >= 0)
            {
                attackTipe = ENUM_AttackType::RightSwing;
            }
            else 
            {
                attackTipe = ENUM_AttackType::LeftSwing;
            }
        }
        else 
        {
            if(directionY >= 0)
            {
                attackTipe = ENUM_AttackType::Stab;
            }
        }

    }

    return attackTipe;
}
