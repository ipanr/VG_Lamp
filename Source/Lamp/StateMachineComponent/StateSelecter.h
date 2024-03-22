/*
Recibe un conjunto de mapeos String-boleano, para determinar el estado al que debe entrar. Cada boleano puede ser determinado por una cantidad enorme de 
condiciones individuales. El orden de a cuál estado entrar primero está puesto directamente en el código en el caso de que se cumplan dos condiciones. La
primera en cumplir las condicionecesarias, será a la que se entrará. DeterminePlayerState se encarga de realizar este proceso.

La clase StateMap en .cpp determina los nombres que deben tener los booleanos al momento de enviarlos en StateInfo


Esta parte del cógigo no se encarga de implementar las nuevas condiciones de movimiento en el personaje, únicamente determina cuál será el estado
en el cuál el personaje se encuentra
*/

#pragma once

#include "../Models/ENUM_States.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "StateSelecter.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UStateSelecter : public UActorComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "StateMachine")
    static ENUM_States DeterminePlayerState(const TMap<FString, bool>& StateInfo);
};
