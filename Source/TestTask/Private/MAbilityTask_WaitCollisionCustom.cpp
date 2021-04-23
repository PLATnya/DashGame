// Fill out your copyright notice in the Description page of Project Settings.


#include "MAbilityTask_WaitCollisionCustom.h"

void UMAbilityTask_WaitCollisionCustom::Activate()
{
	Super::Activate();
	if(PrimitiveComponent)
	{
		PrimitiveComponent->OnComponentBeginOverlap.AddDynamic(this,&UMAbilityTask_WaitCollisionCustom::OnOverlapCallback);
	}	

}

void UMAbilityTask_WaitCollisionCustom::OnDestroy(bool AbilityEnded)
{
	if (PrimitiveComponent)
	{
		
		PrimitiveComponent->OnComponentBeginOverlap.RemoveAll(this);
	}

	Super::OnDestroy(AbilityEnded);
}

UMAbilityTask_WaitCollisionCustom* UMAbilityTask_WaitCollisionCustom::WaitOverlapCustom(UGameplayAbility* OwningAbility,
                                                                        UPrimitiveComponent* Component)
{
	
	UMAbilityTask_WaitCollisionCustom* abilityTask = NewAbilityTask<UMAbilityTask_WaitCollisionCustom>(OwningAbility);
	abilityTask->PrimitiveComponent = Component;
	return abilityTask;

}

void UMAbilityTask_WaitCollisionCustom::OnOverlapCallback(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		auto* targetData = new FGameplayAbilityTargetData_SingleTargetHit();
		targetData->HitResult = SweepResult;
		
		
		FGameplayAbilityTargetDataHandle targetDataHandle = FGameplayAbilityTargetDataHandle(targetData);
		if (ShouldBroadcastAbilityTaskDelegates())
		{
			OnOverlap.Broadcast(targetDataHandle);
		}
	}
}
	
