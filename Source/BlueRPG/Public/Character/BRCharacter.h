// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "Character/BRCharacterBase.h"
#include "BRCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API ABRCharacter : public ABRCharacterBase
{
	GENERATED_BODY()

public:
	ABRCharacter();
	//~ Begin AActor Interface.
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	/** Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface*/
	
private:
	virtual void InitAbilityActorInfo() override;
};
