// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WalkingHorrorUserWidget.generated.h"

class UWalkingHorrorWidgetController;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class WALKINGHORROR_API UWalkingHorrorUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	UFUNCTION(BlueprintCallable)
	TSubclassOf<UWalkingHorrorWidgetController> GetWidgetController();

	//UWalkingHorrorWidgetController* GetWidgetController(const FWidgetControllerParams& WCParams);
	
	//void InitController(APlayerController* PC);
protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

	UFUNCTION()
	void ShowMenu(bool isPaused);

};
