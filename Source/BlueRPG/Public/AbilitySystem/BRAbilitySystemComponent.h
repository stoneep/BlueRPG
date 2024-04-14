// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BRAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API UBRAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void AbilityActorInfoSet();

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
