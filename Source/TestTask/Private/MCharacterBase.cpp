// Fill out your copyright notice in the Description page of Project Settings.


#include "MCharacterBase.h"

// Sets default values
AMCharacterBase::AMCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

