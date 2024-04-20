// Copyright NEXONGames


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/Data/AttributeInfo.h"
#include "AbilitySystem/BRAttributeSet.h"
#include "BRGameplayTags.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UBRAttributeSet* AS = CastChecked<UBRAttributeSet>(AttributeSet);

	check(AttributeInfo);

	FBRAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FBRGameplayTags::Get().Attributes_Primary_Strength);
	Info.AttributeValue = AS->GetStrength();
	AttributeInfoDelegate.Broadcast(Info);
}
