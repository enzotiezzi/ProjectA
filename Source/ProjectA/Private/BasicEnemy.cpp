// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"

#include <PaperZD/Public/PaperZDAnimationComponent.h>
#include <PaperZD/Public/PaperZDAnimInstance.h>

ABasicEnemy::ABasicEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicEnemy::Attack()
{
	if (!bIsAttacking)
	{
		bIsAttacking = true;
		
		GetAnimationComponent()->GetAnimInstance()->JumpToNode("Attack1Node");
	}
}

void ABasicEnemy::ResetCombat()
{
	bIsAttacking = false;
}