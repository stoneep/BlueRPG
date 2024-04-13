// Copyright NEXONGames

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BREffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class BLUERPG_API ABREffectActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ABREffectActor();

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
};
