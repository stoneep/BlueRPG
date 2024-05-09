// Copyright NEXONGames


#include "UI/Widget/BRUserWidget.h"
#include "UObject/ConstructorHelpers.h"

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

// void UBRUserWidget(const FObjectInitializer& ObjectInitializer)
// {
// 	static ConstructorHelpers::FClassFinder<UUserWidget> MainLobbyWidget (TEXT("/Blueprints/UI/Overlay/WBP_MainOverlay"));
// 	if (!ensure(MainLobbyWidget.Class != nullptr)) return;
//
// 	MainLobbyWidgetClass = MainLobbyWidget.Class;
// }

void UBRUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

