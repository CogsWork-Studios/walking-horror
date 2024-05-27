// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WalkingHorrorHUD.generated.h"

class UWalkingHorrorUserWidget;
class UWalkingHorrorWidgetController;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class WALKINGHORROR_API AWalkingHorrorHUD : public AHUD
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, Category = "Menu Widget")
	TObjectPtr<UWalkingHorrorUserWidget> MenuWidget;

	

	UWalkingHorrorWidgetController* GetWidgetController(const FWidgetControllerParams& WCParams);

	void InitController(APlayerController* PC);

protected:
private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UWalkingHorrorUserWidget> UserWidgetClass;


	UPROPERTY()
	TObjectPtr<UWalkingHorrorWidgetController> WidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWalkingHorrorWidgetController> WidgetControllerClass;
};
