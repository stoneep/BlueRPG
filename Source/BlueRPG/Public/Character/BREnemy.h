// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "Character/BRCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "BREnemy.generated.h"

/**
 * 
 */
UCLASS()
class BLUERPG_API ABREnemy : public ABRCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	ABREnemy();

	/**Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/**Enemy Interface */
	
	/** Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/** end Combat Interface*/
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
