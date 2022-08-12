// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include "BaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API ABaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:
	ABaseCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	///////////////////////////////////////////////////
	///
	/// MOVEMENT 
	/// 
	///////////////////////////////////////////////////
	void Move(float AxisValue);

	void StartJumping();

	///////////////////////////////////////////////////
	///
	/// COMBAT 
	/// 
	///////////////////////////////////////////////////
	void Attack();

	UFUNCTION(BlueprintCallable)
	void ResetCombat();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bIsAttacking = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	float AttackRange = 5;
};
