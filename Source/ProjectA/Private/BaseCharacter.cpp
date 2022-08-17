// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <PaperZD/Public/PaperZDAnimationComponent.h>
#include <PaperZD/Public/PaperZDAnimInstance.h>
#include <Paper2D/Classes/PaperFlipbookComponent.h>
#include <BasicEnemy.h>

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");

	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

	SpringArmComponent->SetRelativeRotation(FQuat(FRotator(0, -90, 0)));
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("Move", this, &ABaseCharacter::Move);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseCharacter::StartJumping);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ABaseCharacter::Attack);

	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::Move(float AxisValue)
{
	if (Controller && AxisValue != 0 && bCanMove)
	{
		FVector WorldDirection = FVector::ForwardVector;

		AddMovementInput(WorldDirection, AxisValue);
	}
}

void ABaseCharacter::StartJumping()
{
	if (GetCharacterMovement()->IsMovingOnGround()) 
	{
		Jump();

		GetAnimationComponent()->GetAnimInstance()->JumpToNode("Jump");
	}
}

void ABaseCharacter::Attack() 
{
	if (!bIsAttacking)
	{
		bIsAttacking = true;
		bCanMove = false;

		GetAnimationComponent()->GetAnimInstance()->JumpToNode("Attack1");

		FHitResult HitResult;
		FVector HitLocation = GetActorLocation() + (FVector(GetSprite()->GetRelativeScale3D().X, 0, 0) * AttackRange);
		FCollisionShape CollisionShape = FCollisionShape::MakeSphere(32);

		DrawDebugSphere(GetWorld(), GetActorLocation() + (FVector(GetSprite()->GetRelativeScale3D().X, 0, 0) * AttackRange), 16, 16, FColor::Red, false, 1);
		bool Success = GetWorld()->SweepSingleByChannel(HitResult, HitLocation, HitLocation, FQuat::Identity, ECollisionChannel::ECC_Pawn, CollisionShape);
	
		if (Success)
		{
			if (ABasicEnemy* Enemy = Cast<ABasicEnemy>(HitResult.GetActor()))
			{
				Enemy->ReceiveDamage(2);
			}
		}
	}
}

void ABaseCharacter::ResetCombat()
{
	bIsAttacking = false;

	bCanMove = true;
}