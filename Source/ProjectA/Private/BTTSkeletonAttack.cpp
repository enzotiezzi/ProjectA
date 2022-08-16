// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTSkeletonAttack.h"

#include <AIModule/Classes/AIController.h>
#include <Paper2D/Classes/PaperFlipbookComponent.h>
#include <BasicEnemy.h>
#include <BehaviorTree/Tasks/BTTask_BlueprintBase.h>

UBTTSkeletonAttack::UBTTSkeletonAttack()
{

}

EBTNodeResult::Type UBTTSkeletonAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	if (ABasicEnemy* Enemy = Cast<ABasicEnemy>(OwnerComp.GetAIOwner()->GetPawn()))
	{
		if(!AttackTimerHandle.IsValid())
		{
			Enemy->Attack();

			GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UBTTSkeletonAttack::OnAttackFinish, Enemy->GetSprite()->GetFlipbookLength(), false);
		}
	}

	return EBTNodeResult::InProgress;
}

void UBTTSkeletonAttack::OnAttackFinish()
{
	GetWorld()->GetTimerManager().ClearTimer(AttackTimerHandle);

	FinishExecute(true);
}