// Fill out your copyright notice in the Description page of Project Settings.


#include "CBP_BaseEnemy.h"

// Sets default values
ACBP_BaseEnemy::ACBP_BaseEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACBP_BaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACBP_BaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACBP_BaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

