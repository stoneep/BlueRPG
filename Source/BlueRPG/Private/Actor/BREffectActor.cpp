// Copyright NEXONGames


#include "Actor/BREffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/BRAttributeSet.h"
#include "Components/SphereComponent.h"


ABREffectActor::ABREffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ABREffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//gameplay effect
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UBRAttributeSet* BRAttributeSet = Cast<UBRAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UBRAttributeSet::StaticClass()));

		UBRAttributeSet* MutableBRAttributeSet = const_cast<UBRAttributeSet*>(BRAttributeSet);
		MutableBRAttributeSet->SetHealth(BRAttributeSet->GetHealth() + 25.f);
		//HP+ 25.f is hardcoding
		Destroy();
	}
}

void ABREffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void ABREffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABREffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ABREffectActor::EndOverlap);
}



