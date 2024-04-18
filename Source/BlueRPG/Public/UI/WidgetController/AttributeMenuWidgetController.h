// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BRWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API UAttributeMenuWidgetController : public UBRWidgetController
{
	GENERATED_BODY()

public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;
	
	
};
