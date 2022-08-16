// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <AIModule/Classes/BehaviorTree/Tasks/BTTask_BlueprintBase.h>
#include "CoreMinimal.h"
#include "BTTSkeletonAttack.generated.h"

/**
 * 
 */
UCLASS()
class UBTTSkeletonAttack : public UBTTask_BlueprintBase
{
	GENERATED_BODY()
	
public:
	UBTTSkeletonAttack();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	FTimerHandle AttackTimerHandle;

	UFUNCTION()
	void OnAttackFinish();
};
