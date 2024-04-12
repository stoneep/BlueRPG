// Copyright NEXONGames


#include "Character/BRCharacter.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/BRPlayerState.h"

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
	//InitAbilityActorInfo();
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
	AbilitySystemComponent = BRPlayerState->GetAbilitySystemComponent();
	AttributeSet = BRPlayerState->GetAttributeSet();
}
