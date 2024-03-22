#include "AimingState.h"

void UAimingState::EnterState(TMap<FString, UObject*> objectMap) 
{
    for (auto& Elem : objectMap)
    {
        FString ComponentName = Elem.Key;
        UObject* ComponentObject = Elem.Value;
        if (ComponentName == "Character Movement")
        {
            UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(ComponentObject);
            if (MovementComponent)
            {
                MovementComponent->bOrientRotationToMovement = true;
            }
        }

        //Relacionado con la camara
        if(ComponentName == "Camera")
        {
            CameraComponent = Cast<UCameraComponent>(ComponentObject);
        }

        if(ComponentName == "Spring Arm Default Camera")
        {
            SpringArmComponent = Cast<USpringArmComponent>(ComponentObject);
        }

        if(ComponentName == "Self")
        {
            Self = Cast<ACharacter>(ComponentObject);
        }
    }

    //Posicionar la cámara en el spring arm adecuado
    CameraComponent->AttachToComponent(SpringArmComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);

    UE_LOG(LogTemp, Warning, TEXT("******* Entering Aiming *******"));
}

void UAimingState::ExitState(TMap<FString, UObject*> objectMap) 
{

}

void UAimingState::UpdateState(TMap<FString, UObject*> objectMap) 
{

}
