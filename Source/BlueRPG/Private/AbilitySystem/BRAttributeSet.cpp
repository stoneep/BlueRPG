// Copyright NEXONGames


#include "AbilitySystem/BRAttributeSet.h"
#include "Net/UnrealNetwork.h"

UBRAttributeSet::UBRAttributeSet()
{
	InitHealth(100.f);
	InitMaxHealth(100.f);
}

void UBRAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBRAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBRAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	// Always - If the value is set on the server, rep it and on the client
	// OnChanged - If you set the value of health on the server and that value hasn't changed, then there will be no rep.
}

void UBRAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBRAttributeSet, Health, OldHealth);
}

void UBRAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBRAttributeSet, Health, OldMaxHealth);
}
