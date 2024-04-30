// Fill out your copyright notice in the Description page of Project Settings.


#include "EmmaAnimInstance.h"
#include "Emma.h"
#include "GameFramework/CharacterMovementComponent.h"

UEmmaAnimInstance::UEmmaAnimInstance() :
	bCrouch(false),bRunning(false), bIsInAir(false),
	Speed(0.0f)
{
}
void UEmmaAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (Emma == nullptr) {
		CastActor();
	}
	if (Emma) {
		//Get crouching/running data from emma.cpp
		bCrouch = Emma->GetCrouching();
		bRunning = Emma->GetIsRunning();

		//Get Speed
		FVector Velocity{ Emma->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();
		bIsInAir = Emma->GetCharacterMovement()->IsFalling();
		
		//Instructs BP to Change from Idle to Run/Walk
		if (Emma->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			bIsAccelerating = true;
		}
		else {
			bIsAccelerating = false;
		}

	}
}

void UEmmaAnimInstance::NativeInitializeAnimation()
{
	//Create Coupling between Character class and Anim Instance
	CastActor();
}

void UEmmaAnimInstance::CastActor()
{
	Emma = Cast<AEmma>(TryGetPawnOwner());
}
