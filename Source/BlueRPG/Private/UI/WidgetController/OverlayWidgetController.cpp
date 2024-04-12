// Copyright NEXONGames


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/BRAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	UBRAttributeSet* BRAttributeSet = CastChecked<UBRAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BRAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BRAttributeSet->GetMaxHealth());
}
