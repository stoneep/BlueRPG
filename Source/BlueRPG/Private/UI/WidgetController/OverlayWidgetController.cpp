// Copyright NEXONGames


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/BRAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBRAttributeSet* BRAttributeSet = CastChecked<UBRAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BRAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BRAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBRAttributeSet* BRAttributeSet = CastChecked<UBRAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BRAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		BRAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
}
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
