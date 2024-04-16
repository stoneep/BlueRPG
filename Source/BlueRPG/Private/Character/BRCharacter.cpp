// Copyright NEXONGames


#include "Character/BRCharacter.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/BRAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/BRPlayerController.h"
#include "Player/BRPlayerState.h"
#include "UI/HUD/BRHUD.h"

ABRCharacter::ABRCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ABRCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitAbilityActorInfo();
}

void ABRCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ABRCharacter::InitAbilityActorInfo()
{
	/* Init ability actor info for the Server
	 * to access the player state
	 */
	ABRPlayerState* BRPlayerState = GetPlayerState<ABRPlayerState>();
	check(BRPlayerState);
	BRPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(BRPlayerState, this);
	Cast<UBRAbilitySystemComponent>(BRPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = BRPlayerState->GetAbilitySystemComponent();
	AttributeSet = BRPlayerState->GetAttributeSet();

	if (ABRPlayerController* BRPlayerController = Cast<ABRPlayerController>(GetController()))
	{
		if (ABRHUD* BRHUD = Cast<ABRHUD>(BRPlayerController->GetHUD()))
		{
			BRHUD->InitOverlay(BRPlayerController, BRPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitializePrimaryAttributes();
}
