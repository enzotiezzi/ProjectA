// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <BasicEnemy.h>
#include "Wave.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTA_API UWave : public UObject
{
	GENERATED_BODY()
	
public:
	UWave();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int Id;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<TSubclassOf<ABasicEnemy>> Enemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool bIsTimeBased = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimeUntilSpawnInSeconds = false;
};