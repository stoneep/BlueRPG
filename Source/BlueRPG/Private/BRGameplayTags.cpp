// Copyright NEXONGames


#include "BRGameplayTags.h"
#include "GameplayTagsManager.h"

FBRGameplayTags FBRGameplayTags::GameplayTags;

void FBRGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
}
