// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BRAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API UBRAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UBRAssetManager& Get();

protected:

	virtual void StartInitialLoading() override;
};
