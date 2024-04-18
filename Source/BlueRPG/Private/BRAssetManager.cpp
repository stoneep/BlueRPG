// Copyright NEXONGames


#include "BRAssetManager.h"
#include  "BRGameplayTags.h"


UBRAssetManager& UBRAssetManager::Get()
{
	check(GEngine);
	UBRAssetManager* BRAssetManager = Cast<UBRAssetManager>(GEngine->AssetManager);
	return *BRAssetManager;
}

void UBRAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FBRGameplayTags::InitializeNativeGameplayTags();
}
