// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "BasicEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API ABasicEnemy : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	ABasicEnemy();

	void Attack();

	UFUNCTION(BlueprintCallable)
	void ResetCombat();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAttacking = false;
};