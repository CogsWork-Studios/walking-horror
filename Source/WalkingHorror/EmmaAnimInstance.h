// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EmmaAnimInstance.generated.h"


UENUM(BlueprintType)
enum class EDirectionOrientation : uint8 {
	E_Left UMETA(DisplayName = "Left Orientation"),
	E_Right UMETA(DisplayName = "Right Orientation"),
	E_Forward UMETA(DisplayName = "Forward Orientation"),
	E_Backward UMETA(DisplayName = "Backward Orientation"),
};

/**
 * 
 */
UCLASS()
class WALKINGHORROR_API UEmmaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UEmmaAnimInstance();

	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);

	virtual void NativeInitializeAnimation() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess ="true"))
	class AEmma* Emma;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UAnimInstance* EmmaAnimInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	EDirectionOrientation DirectionOrientation;

	void CastActor();

	/** Speed of character*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Speed;
	/**Whether or not the character is in the air*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;
	/**Whether or not the character is crouching*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bCrouch;
	/**Whether or not the character is running*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bRunning;
	/**Whether or not the character is Accelerating*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Direction;

};	
