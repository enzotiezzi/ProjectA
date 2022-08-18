// Fill out your copyright notice in the Description page of Project Settings.

#include "WaveSpawner.h"
#include <Components/ArrowComponent.h>

AWaveSpawner::AWaveSpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnArrow = CreateDefaultSubobject<UArrowComponent>("UArrowComponent");

	SpawnArrow->SetupAttachment(GetRootComponent());
}

void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<UWave> WaveSubObject: Waves)
	{
		if (UWave* Wave = Cast<UWave>(WaveSubObject.GetDefaultObject()))
		{
			float CurrentDelayToSpawn = TimeToSpawnNextEnemyInSeconds;

			for (TSubclassOf<ABasicEnemy> EnemySubObject : Wave->Enemies)
			{
			
				FTimerHandle SpawnTimer;
				GetWorld()->GetTimerManager().SetTimer(SpawnTimer, [this, EnemySubObject, SpawnTimer]()
					{
						ABasicEnemy* Enemy = GetWorld()->SpawnActor<ABasicEnemy>(EnemySubObject, SpawnArrow->GetComponentLocation(), FRotator(0, 0, 0), FActorSpawnParameters());
					}, CurrentDelayToSpawn, false);

				CurrentDelayToSpawn += TimeToSpawnNextEnemyInSeconds;
			}
		}
	}
}