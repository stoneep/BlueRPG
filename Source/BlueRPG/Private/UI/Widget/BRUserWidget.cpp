// Copyright NEXONGames


#include "UI/Widget/BRUserWidget.h"

// void UBRUserWidget::RegenerateAllEntries()
// {
// 	EntryWidgetPool.ReleaseAll();
// 	
// }
//
// void UBRUserWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
// {
// 	Execute_OnListItemObjectSet(Cast<UObject>(this), ListItemObject);
// }

void UBRUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

