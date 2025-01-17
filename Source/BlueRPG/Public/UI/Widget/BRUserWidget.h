// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "Components/ListViewBase.h"
#include "BRUserWidget.generated.h"

class UGameInstance;
class UObject;
//class UserWidgetPool;
//class UListView;
/**
 * 
 */
UCLASS()
class BLUERPG_API UBRUserWidget : public UUserWidget // public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	
	//void UBRUserWidget(const FObjectInitializer& ObjectInitializer);
	
	// UFUNCTION(BlueprintCallable, Category = "BRListViewBase")
	// void RegenerateAllEntries();
	//
	// UPROPERTY(Transient)
	// FUserWidgetPool EntryWidgetPool;
	//
	// virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

private:
	

	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
