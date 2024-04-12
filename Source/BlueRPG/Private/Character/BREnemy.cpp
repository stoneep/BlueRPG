// Copyright NEXONGames


#include "Character/BREnemy.h"

#include "BlueRPG/BlueRPG.h"

ABREnemy::ABREnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
