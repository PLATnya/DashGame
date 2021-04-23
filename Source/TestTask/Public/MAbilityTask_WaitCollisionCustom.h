// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "MAbilityTask_WaitCollisionCustom.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWaitOverlapDelegate, const FGameplayAbilityTargetDataHandle&, HitData);

UCLASS()
class TESTTASK_API UMAbilityTask_WaitCollisionCustom : public UAbilityTask
{
	GENERATED_BODY()


	UPROPERTY(BlueprintAssignable)
	FWaitOverlapDelegate OnOverlap;
	
	UPROPERTY()
	UPrimitiveComponent* PrimitiveComponent;
	virtual void Activate() override;

	virtual void OnDestroy(bool AbilityEnded) override;
	public:
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (HidePin = "OwningAbility", DefaultToSelf = "OwningAbility"))
    static UMAbilityTask_WaitCollisionCustom* WaitOverlapCustom(UGameplayAbility* OwningAbility, UPrimitiveComponent* Component);
	
	UFUNCTION() 
    void OnOverlapCallback(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
