// Copyright NEXONGames


#include "Character/BRCharacterBase.h"


ABRCharacterBase::ABRCharacterBase()
{

	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ABRCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void ABRCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABRCharacterBase::InitAbilityActorInfo()
{
}
