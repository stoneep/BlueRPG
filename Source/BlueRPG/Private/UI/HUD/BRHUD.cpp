// Copyright NEXONGames


#include "UI/HUD/BRHUD.h"
#include "UI/Widget/BRUserWidget.h"

void ABRHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
