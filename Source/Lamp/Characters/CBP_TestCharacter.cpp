#include "CBP_TestCharacter.h"
#include "../StateMachineComponent/StateMachine.h"
#include "../StateMachineComponent/StateSelecter.h"
#include "../Models/ENUM_States.h"
#include "../Abilities/DefaultAbility.h"

ACBP_TestCharacter::ACBP_TestCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//StateMachine = CreateDefaultSubobject<UStateMachine>("StateMachine");  // por alguna razón crashea después de cierto tiempo
	StateSelector = CreateDefaultSubobject<UStateSelecter>("StateSelector");
}

void ACBP_TestCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ACBP_TestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACBP_TestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
