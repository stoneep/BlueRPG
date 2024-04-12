// Copyright NEXONGames


#include "Player/BRPlayerState.h"

#include "AbilitySystem/BRAbilitySystemComponent.h"
#include "AbilitySystem/BRAttributeSet.h"

ABRPlayerState::ABRPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UBRAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UBRAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ABRPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
