#include "TargettingState.h"

FVector GetFocusPoint(UCapsuleComponent* mainCharacter, APawn* targetObject)
{
    FVector mainCharacterLocation = mainCharacter->GetComponentLocation();
    FVector targetEntityLocation = targetObject->GetActorLocation();
    FVector battleCameraTargetFinalLocation;

    float xComponent = (mainCharacterLocation.X + targetEntityLocation.X)/2;
    float yComponent = (mainCharacterLocation.Y + targetEntityLocation.Y)/2;
    float zComponent = (mainCharacterLocation.Z + targetEntityLocation.Z)/2;

    battleCameraTargetFinalLocation = FVector(xComponent, yComponent, zComponent);

    return battleCameraTargetFinalLocation;
}

void UTargettingState::EnterState(TMap<FString, UObject*> objectMap) 
{
    //UniversalActionMap = objectMap;

    for (auto& Elem : objectMap)
    {
        FString ComponentName = Elem.Key;
        UObject* ComponentObject = Elem.Value;

        //si genero una referencia crashea, entonces lo dejé así
        if (ComponentName == "Character Movement")
        {
            UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(ComponentObject);
            if (MovementComponent)
            {
                MovementComponent->bOrientRotationToMovement = false;
            }
        }

        //Relacionado con la camara
        if(ComponentName == "Camera")
        {
            cameraComponent = Cast<UCameraComponent>(ComponentObject);
        }

        if(ComponentName == "Spring Arm Battle Camera")
        {
            springArmComponent = Cast<USpringArmComponent>(ComponentObject);
        }

        if(ComponentName == "Capsule Component")
        {
            capsuleCollision = Cast<UCapsuleComponent>(ComponentObject);
        }

        if(ComponentName == "Self")
        {
            Self = Cast<ACharacter>(ComponentObject);
        }

        if(ComponentName == "Battle Camera Target")
        {
            battleCameraTarget = Cast<USceneComponent>(ComponentObject);
        }

        if(ComponentName == "Target Entity")
        {
            targetEntity = Cast<APawn>(ComponentObject);
        }
        
    }

    //poner la cámara en el spring arm seleccionado
    cameraComponent->AttachToComponent(springArmComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
    //Posicionar el battle Camera Tarjet Relativo a la distancia entre el pawn y el tarjet
    if(capsuleCollision && targetEntity)
    {
        FVector battleCameraTargetFinalLocation = GetFocusPoint(capsuleCollision, targetEntity);
        battleCameraTarget->SetWorldLocation(battleCameraTargetFinalLocation);
    }
    UE_LOG(LogTemp, Warning, TEXT("******* Entering Target *******"));
}

void UTargettingState::ExitState(TMap<FString, UObject*> objectMap)
{

}

void UTargettingState::UpdateState(TMap<FString, UObject*> objectMap)
{

}

void UTargettingState::Move(float inputX, float inputY)
{
    FVector cameraForwardVector = cameraComponent->GetForwardVector();
    FVector proyectedCameraForward = FVector(cameraForwardVector.X, cameraForwardVector.Y, 0);
    FVector NormalizedProyectedCameraForward = proyectedCameraForward.GetSafeNormal();

    FVector cameraRightVector = cameraComponent->GetRightVector();
    FVector proyectedCameraRight = FVector(cameraRightVector.X, cameraRightVector.Y, 0);
    FVector normalizedCameraRightVector = proyectedCameraRight.GetSafeNormal();

    //Rotar al personaje para que encare al target
    FVector characterLocation = capsuleCollision->GetComponentLocation();
    FVector targetLocation = targetEntity->GetActorLocation();
    FRotator lookAtRotation = UKismetMathLibrary::FindLookAtRotation(characterLocation, targetLocation);
    FRotator mainCharacterRotation = capsuleCollision->GetComponentRotation();
    FRotator interpolatedRotation = FMath::RInterpTo(mainCharacterRotation, lookAtRotation, 0.01, 20.0);
    FRotator finalCharacterRotation = FRotator(0.0f,interpolatedRotation.Yaw,0.0f);

    if(Self)
    {
        Self->AddMovementInput(NormalizedProyectedCameraForward, inputX);
        Self->AddMovementInput(normalizedCameraRightVector, inputY);

        Self->SetActorRotation(finalCharacterRotation);
    } 

    //Posicionar el target de la camara a la mitad del pawn y el enemigo
    FVector finalTargetEntityLocation = FVector((characterLocation.X+targetLocation.X)/2,(characterLocation.Y+targetLocation.Y)/2,(characterLocation.Z+targetLocation.Z)/2);

    if(targetEntity) 
    {
        battleCameraTarget->SetWorldLocation(finalTargetEntityLocation);
    }
}
