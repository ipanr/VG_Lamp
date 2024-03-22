#include "StateMachine.h"

UStateMachine::UStateMachine() : currentState(nullptr) 
{
    aimingState = NewObject<UAimingState>();
    targettingState = NewObject<UTargettingState>();
    baseState = NewObject<UBaseState>();
    currentState = baseState;
}

void UStateMachine::SetState(ENUM_States NewState, TMap<FString, UObject*> ActorMap)
{
    if(currentState)
    {
        currentState -> ExitState(ActorMap);
    }	

    switch (NewState)
    {
        case ENUM_States::Targeting:
            currentState = targettingState;
        break;
        case ENUM_States::Aiming:
            currentState = aimingState;
        break;
        default:
            currentState = baseState;
        break;
    }

    if(currentState) 
    {
        currentState -> EnterState(ActorMap);
    }
}

void UStateMachine::Update(TMap<FString, UObject*> ActorMap) 
{
    if(currentState) 
    {
        currentState -> UpdateState(ActorMap);
    }
}

void UStateMachine::Move(float inputX, float inputY)
{
    try
    {
        if(currentState) 
        {
            currentState -> Move(inputX, inputY);
        } else 
        {
            UE_LOG(LogTemp, Warning, TEXT("ERROR AL DERECTAR CURRENT STATE"));
        }
    } catch (...) 
    { 
        UE_LOG(LogTemp, Warning, TEXT("Excepción cachada"));
    }

}

/*Función agregada para mostrar el crash del juego. En algún momento desaparece el puntero hacie currentState y crashea. 
Si mandamos a llamar Move(), después de cierto tiempo la referencia desaparece. 
Probar en otras arquitecturas de Unreal, otros builds, dockerizar, o algo para ver si falla en otras computadoras.
*/
void UStateMachine::TestFunction(TMap<FString, UObject*> ActorMap)
{
    try
    {
    if (IsValid(currentState))
    {
        currentState->Move(0.01, 0.01);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("CurrentState is not valid."));
    }
    }
    catch(...)
    {
        UE_LOG(LogTemp, Warning, TEXT("CurrentState is not valid."));
    }
}
