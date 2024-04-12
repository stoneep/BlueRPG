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

protected:
	virtual void BeginPlay() override;
};
