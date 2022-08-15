// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <Wave.h>
#include "WaveSpawner.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTA_API AWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AWaveSpawner();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Waves")
	TArray<TSubclassOf<UWave>> Waves;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UArrowComponent* SpawnArrow;
};
