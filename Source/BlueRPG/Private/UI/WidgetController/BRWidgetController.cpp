// Copyright NEXONGames


#include "UI/WidgetController/BRWidgetController.h"


void UBRWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UBRWidgetController::BroadcastInitialValues()
{
}

void UBRWidgetController::BindCallbacksToDependencies()
{
}
