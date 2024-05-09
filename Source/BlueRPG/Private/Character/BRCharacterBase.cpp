// Copyright NEXONGames


#include "Character/BRCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BRAbilitySystemComponent.h"


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

void ABRCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ABRCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
	ApplyEffectToSelf(DefaultEtcAttributes, 1.f);
}

void ABRCharacterBase::AddCharacterAbilities()
{
	UBRAbilitySystemComponent* BRASC = CastChecked<UBRAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	BRASC->AddCharacterAbilities(StartupAbilities);
}

// void ABRCharacterBase::InitializePrimaryAttributes() const
// {
// 	check(IsValid(GetAbilitySystemComponent()));
// 	check(DefaultPrimaryAttributes);
// 	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
// 	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
// 	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
// 	//65
// }
//
// void ABRCharacterBase::InitializeSecondaryAttributes() const
// {
// 	check(IsValid(GetAbilitySystemComponent()));
// 	check(DefaultSecondaryAttributes);
// 	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
// 	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultSecondaryAttributes, 1.f, ContextHandle);
// 	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
// }
