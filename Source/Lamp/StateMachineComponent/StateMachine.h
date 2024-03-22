/*
Gestiona los cambios de estado dependiendo del estado en el que se encuentre. Por alguna razón crashea después de un tiempo de estarse ejecutando.
La referencia a CurrentState se pierde totalmente, lo que provoca un null pointer exception. 

Probar en otros builds de Unreal para determinar si es mi build u otro problema
*/

#pragma once

#include "../Models/ENUM_States.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "../Models/BaseState.h"
#include "../States/AimingState.h"
#include "../States/TargettingState.h"
#include "StateMachine.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UStateMachine: public UActorComponent
{

	GENERATED_BODY()

public:
	UStateMachine();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StateMachine")
	ENUM_States Enum_CurrentState;

	UFUNCTION(BlueprintCallable)
	void SetState(ENUM_States NewState, TMap<FString, UObject*> ActorMap);
	UFUNCTION(BlueprintCallable)
	void Update(TMap<FString, UObject*> ActorMap);
	UFUNCTION(BlueprintCallable)
	void Move(float inputX, float inputY);
	UFUNCTION(BlueprintCallable)
	void TestFunction(TMap<FString, UObject*> ActorMap);

private:
	UBaseState* currentState;
	UBaseState* baseState;
	UAimingState* aimingState;
	UTargettingState* targettingState;
};
