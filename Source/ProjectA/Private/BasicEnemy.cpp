// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemy.h"

#include <PaperZD/Public/PaperZDAnimationComponent.h>
#include <PaperZD/Public/PaperZDAnimInstance.h>
#include <SkeletonAIController.h>

ABasicEnemy::ABasicEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasicEnemy::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
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

	bIsTakingHit = false;

	if (ASkeletonAIController* AIController = Cast<ASkeletonAIController>(GetController()))
	{
		if(AIController->BrainComponent->IsPaused())
			AIController->BrainComponent->ResumeLogic("ResetCombat");
	}
}

float ABasicEnemy::ReceiveDamage(float DamageAmount)
{
	if (!bIsTakingHit)
	{
		bIsTakingHit = true;

		if (ASkeletonAIController* AIController = Cast<ASkeletonAIController>(GetController()))
		{
			AIController->BrainComponent->PauseLogic("Hit");
		}

		CurrentHealth -= DamageAmount;

		if (CurrentHealth <= 0)
			GetAnimationComponent()->GetAnimInstance()->JumpToNode("DeadNode");
		else
			GetAnimationComponent()->GetAnimInstance()->JumpToNode("DamageNode");
	}

	return CurrentHealth;
}