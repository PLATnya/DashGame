// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "MStatsSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
UCLASS()
class TESTTASK_API UMStatsSet : public UAttributeSet
{
	GENERATED_BODY()
	public:
	UMStatsSet();
	
	UPROPERTY(BlueprintReadOnly)
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UMStatsSet, Health)
};
