#pragma once

#include "../StateMachineComponent/StateMachine.h"
#include "../StateMachineComponent/StateSelecter.h"
#include "../Models/ENUM_States.h"
#include "../Models/BaseAbility.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CBP_TestCharacter.generated.h"

UCLASS()
class LAMP_API ACBP_TestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACBP_TestCharacter();

protected:
	virtual void BeginPlay() override;

	//Componentes con funciones
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StateMachine")
    class UStateMachine* StateMachine;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StateMachine")
    class UStateSelecter* StateSelector;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Abilities")
    TArray<UBaseAbility*> AbilityManager;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
