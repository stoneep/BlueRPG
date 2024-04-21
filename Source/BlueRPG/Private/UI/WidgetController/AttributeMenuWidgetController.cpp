// Copyright NEXONGames


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/Data/AttributeInfo.h"
#include "AbilitySystem/BRAttributeSet.h"




void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UBRAttributeSet* AS = CastChecked<UBRAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadCastAttributeInfo(Pair.Key, Pair.Value());
			// FBRAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
			// Info.AttributeValue = Pair.Value().GetNumericValue(AS);
			// AttributeInfoDelegate.Broadcast(Info);
		}
	);
	}
}



	
void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UBRAttributeSet* AS = CastChecked<UBRAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Pair: AS->TagsToAttributes)
	{
		BroadCastAttributeInfo(Pair.Key, Pair.Value());
		// FBRAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		// Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		// AttributeInfoDelegate.Broadcast(Info);
	}
}

void UAttributeMenuWidgetController::BroadCastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FBRAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
