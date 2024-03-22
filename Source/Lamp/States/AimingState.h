#pragma once
#include "../Models/BaseState.h"
#include "Kismet/KismetMathLibrary.h"
#include "AimingState.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAimingState : public UBaseState
{
    GENERATED_BODY()

    public:
    virtual void EnterState(TMap<FString, UObject*> objectMap) override;
    virtual void ExitState(TMap<FString, UObject*> objectMap) override;
    virtual void UpdateState(TMap<FString, UObject*> objectMap) override;
    //virtual void Move(float inputX, float inputY) override;
};
