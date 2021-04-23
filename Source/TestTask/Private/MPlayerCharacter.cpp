// Fill out your copyright notice in the Description page of Project Settings.


#include "MPlayerCharacter.h"



void AMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(DamagedDashAbility,0,0,this));
}
