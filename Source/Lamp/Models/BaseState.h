#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "Containers/Map.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "BaseState.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UBaseState : public UObject
{
    GENERATED_BODY()

public:
    UBaseState();

    UFUNCTION(BlueprintCallable, Category = "State")
    virtual void EnterState(TMap<FString, UObject*> objectMap);

    UFUNCTION(BlueprintCallable, Category = "State")
    virtual void ExitState(TMap<FString, UObject*> objectMap);

    UFUNCTION(BlueprintCallable, Category = "State")
    virtual void UpdateState(TMap<FString, UObject*> objectMap);

    UFUNCTION(BlueprintCallable, Category = "State")
    virtual void Move(float inputX, float inputY);

    USpringArmComponent* SpringArmComponent;
    UCameraComponent* CameraComponent;
    ACharacter* Self;
    UCharacterMovementComponent* GlobalMovementComponent;

    FVector MovementXVector;
};