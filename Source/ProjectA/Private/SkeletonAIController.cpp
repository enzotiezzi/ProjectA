// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletonAIController.h"
#include <AIModule/Classes/Perception/AIPerceptionComponent.h>
#include <AIModule/Classes/BehaviorTree/BlackboardComponent.h>
#include <BaseCharacter.h>

ASkeletonAIController::ASkeletonAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerceptionComponent");

	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ASkeletonAIController::OnTargetPerceptionUpdated);
}

void ASkeletonAIController::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		bool Success = RunBehaviorTree(BehaviorTree);
	}
}

void ASkeletonAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	AActor* CurrentTarget = Cast<AActor>(GetBlackboardComponent()->GetValueAsObject("Target"));
	
	if (ABaseCharacter* Player = Cast<ABaseCharacter>(Actor))
	{
		GetBlackboardComponent()->SetValueAsObject("Target", Actor);
	}
}