// Copyright NEXONGames


#include "AbilitySystem/BRAbilitySystemLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "Player/BRPlayerState.h"
#include "UI/HUD/BRHUD.h"
#include "UI/WidgetController/BRWidgetController.h"

UOverlayWidgetController* UBRAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ABRHUD* BRHUD = Cast<ABRHUD>(PC->GetHUD()))
		{

			ABRPlayerState* PS = PC->GetPlayerState<ABRPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return BRHUD->GetOverlayWidgetController(WidgetControllerParams);
			
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UBRAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ABRHUD* BRHUD = Cast<ABRHUD>(PC->GetHUD()))
		{

			ABRPlayerState* PS = PC->GetPlayerState<ABRPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return BRHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
			
		}
	}
	return nullptr;
}
