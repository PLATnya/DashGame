// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MCharacterBase.h"
#include "MStatsSet.h"
#include "MEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API AMEnemyCharacter : public AMCharacterBase
{
	GENERATED_BODY()

	protected:
	UFUNCTION()
    void OnGameplayEffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle);
	virtual void BeginPlay() override;
	public:

	AMEnemyCharacter();
		UPROPERTY()
		UMStatsSet* StatsSet;
};
