// Copyright NEXONGames


#include "Character/BRCharacterBase.h"

#include "AbilitySystemComponent.h"


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

void ABRCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	//65
}
