// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <AIModule/Classes/Perception/AIPerceptionComponent.h>
#include <AIModule/Classes/BehaviorTree/BehaviorTree.h>
#include <Perception/AIPerceptionTypes.h>
#include "SkeletonAIController.generated.h"

/**
 * 
 */
UCLASS()
class ASkeletonAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASkeletonAIController();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBehaviorTree* BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAIPerceptionComponent* AIPerceptionComponent;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);
};
