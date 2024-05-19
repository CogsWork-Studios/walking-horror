// Fill out your copyright notice in the Description page of Project Settings.

#include "WalkingHorror.h"
#include "MySaveGame.h"
#include "Emma.h"

UMySaveGame::UMySaveGame()
{
	PlayerName = TEXT("Emma");
	PlayerPosition = FVector(0.f, 0.f, 0.f);
	SaveSlotName = TEXT("Slot1");
	UserIndex = 0;
}

void UMySaveGame::Save(AEmma* emmaData)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	// Set data on the savegame object.
	SaveGameInstance->PlayerName = TEXT("PlayerOne");
	SaveGameInstance->PlayerPosition = emmaData->GetActorLocation();

	// Start async save process.
	UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, TEXT("SaveSlotName"), 0);
}

void UMySaveGame::Load(AEmma* emmaData)
{
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveSlotName"), 0));
	emmaData->SetActorLocation(SaveGameInstance->PlayerPosition);
}