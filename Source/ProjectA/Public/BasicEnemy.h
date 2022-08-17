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

	virtual void BeginPlay() override;

	void Attack();

	float ReceiveDamage(float DamageAmount);

	UFUNCTION(BlueprintCallable)
	void ResetCombat();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsAttacking = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsTakingHit = false;
};