// Copyright NEXONGames


#include "UI/Widget/BRUserWidget.h"

void UBRUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
