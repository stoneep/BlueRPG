// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"


/**
 * BRGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FBRGameplayTags
{
public:

	static const FBRGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Secondary_Armor;

	

private:
	
	static FBRGameplayTags GameplayTags;
	
};


