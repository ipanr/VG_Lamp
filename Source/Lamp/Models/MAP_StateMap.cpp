/*
Mapa de los estados accesibles para el jugador
*/

#include "MAP_StateMap.h"

TMap<FString, ENUM_States> StateMap = 
{
    { "IdleWalkRun", ENUM_States::IdleWalkRun },
    { "OnAir", ENUM_States::OnAir },
    { "Train", ENUM_States::Train },
};
