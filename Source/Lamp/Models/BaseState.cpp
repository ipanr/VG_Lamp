#include "BaseState.h"

UBaseState::UBaseState()
{
    // Constructor
}

void UBaseState::EnterState(TMap<FString, UObject*> objectMap)
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

    UE_LOG(LogTemp, Warning, TEXT("******* Entering Base *******"));
}

void UBaseState::ExitState(TMap<FString, UObject*> objectMap)
{

}

void UBaseState::UpdateState(TMap<FString, UObject*> objectMap)
{

}


void UBaseState::Move(float inputX, float inputY)
{
    FVector cameraForwardVector = CameraComponent->GetForwardVector();
    FVector proyectedCameraForward = FVector(cameraForwardVector.X, cameraForwardVector.Y, 0);
    FVector NormalizedProyectedCameraForward = proyectedCameraForward.GetSafeNormal();

    FVector cameraRightVector = CameraComponent->GetRightVector();
    FVector proyectedCameraRight = FVector(cameraRightVector.X, cameraRightVector.Y, 0);
    FVector normalizedCameraRightVector = proyectedCameraRight.GetSafeNormal();

    if(Self)
    {
        Self->AddMovementInput(NormalizedProyectedCameraForward, inputX);
        Self->AddMovementInput(normalizedCameraRightVector, inputY);
    }  
}

