#include "StateSelecter.h"
#include "../Models/MAP_StateMap.h"

ENUM_States UStateSelecter::DeterminePlayerState(const TMap<FString, bool>& StateInfo)
{
    for (const auto& Elem : StateInfo)
    {
        if (Elem.Value)
        {
            const ENUM_States* PlayerState = StateMap.Find(Elem.Key);
            if (PlayerState)
            {
                return *PlayerState;
            }
        }
    }

    return ENUM_States::IdleWalkRun;
}
