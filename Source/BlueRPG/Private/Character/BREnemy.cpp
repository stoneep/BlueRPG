// Copyright NEXONGames


#include "Character/BREnemy.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BRAbilitySystemComponent.h"
#include "AbilitySystem/BRAttributeSet.h"
#include "BlueRPG/BlueRPG.h"

ABREnemy::ABREnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UBRAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UBRAttributeSet>("AttributeSet");
}

void ABREnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ABREnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
}

void ABREnemy::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityActorInfo();
}

void ABREnemy::InitAbilityActorInfo()
{
	//check(AbilitySystemComponent)' -> NULL
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	//Initializing that in the constructor->BREnemy
	Cast<UBRAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
