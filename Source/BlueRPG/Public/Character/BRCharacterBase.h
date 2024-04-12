// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BRCharacterBase.generated.h"

UCLASS(Abstract)
class BLUERPG_API ABRCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	ABRCharacterBase();

protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
