// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/BRUserWidget.h"
#include "BRHUD.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API ABRHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UBRUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBRUserWidget> OverlayWidgetClass;
};
