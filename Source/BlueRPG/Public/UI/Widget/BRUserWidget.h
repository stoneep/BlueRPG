// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BRUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API UBRUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
