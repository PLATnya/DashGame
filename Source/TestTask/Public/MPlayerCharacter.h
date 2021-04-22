// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MCharacterBase.h"
#include "MPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTTASK_API AMPlayerCharacter : public AMCharacterBase
{
	GENERATED_BODY()
	protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> DamagedDashAbility;
	virtual void BeginPlay() override;
};
