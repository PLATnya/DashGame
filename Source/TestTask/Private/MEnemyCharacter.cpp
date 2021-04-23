// Fill out your copyright notice in the Description page of Project Settings.


#include "MEnemyCharacter.h"


#include "GameFramework/CharacterMovementComponent.h"

void AMEnemyCharacter::OnGameplayEffectApplied(UAbilitySystemComponent* Source, const FGameplayEffectSpec& Spec,
                                               FActiveGameplayEffectHandle Handle)
{
	FGameplayTagContainer EffectTagsContainer;
	Spec.GetAllAssetTags(EffectTagsContainer);
	
	const bool IsDamage = EffectTagsContainer.HasTag(FGameplayTag::RequestGameplayTag("Effect.Damage"));
	if(IsDamage)
	{
		const float Force = Spec.Modifiers[0].GetEvaluatedMagnitude();
		AActor* instigator = Spec.GetEffectContext().GetInstigator();		
		
		const FVector direction = (GetActorLocation() -instigator->GetActorLocation()) + instigator->GetActorForwardVector() + FVector::UpVector*5;
		TSharedPtr<FRootMotionSource_ConstantForce> constantForce(new FRootMotionSource_ConstantForce());
		constantForce->AccumulateMode = ERootMotionAccumulateMode::Additive;
		constantForce->Force = -direction * Force;
		constantForce->Duration = 0.1f;
		constantForce->FinishVelocityParams.Mode = ERootMotionFinishVelocityMode::MaintainLastRootMotionVelocity;
		GetCharacterMovement()->MovementMode = EMovementMode::MOVE_Falling;
		GetCharacterMovement()->ApplyRootMotionSource(constantForce);
	}
	
}

void AMEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &AMEnemyCharacter::OnGameplayEffectApplied);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StatsSet->GetHealthAttribute()).AddUObject(this, &AMEnemyCharacter::HealthChanged);
}

void AMEnemyCharacter::HealthChanged(const FOnAttributeChangeData& Data)
{
	if (Data.NewValue <= 0) Death();
}

void AMEnemyCharacter::Death_Implementation()
{
}

AMEnemyCharacter::AMEnemyCharacter()
{
	StatsSet = CreateDefaultSubobject<UMStatsSet>("Stats");
}
