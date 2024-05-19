// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Emma.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class WALKINGHORROR_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;
	
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FVector PlayerPosition;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;
	
	UMySaveGame();
	static void Save(AEmma* emmaData);
	static void Load(AEmma* emmaData);
};
