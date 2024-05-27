// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkingHorrorUserWidget.h"
#include "WalkingHorrorWidgetController.h"
#include <Kismet/GameplayStatics.h>

void UWalkingHorrorUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
TSubclassOf<UWalkingHorrorWidgetController> UWalkingHorrorUserWidget::GetWidgetController()
{
	return TSubclassOf<UWalkingHorrorWidgetController>();
}
void UWalkingHorrorUserWidget::ShowMenu(bool bPauseAndShowMenu)
{
	if (bPauseAndShowMenu) {
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
	
}
/*
UWalkingHorrorWidgetController* UWalkingHorrorUserWidget::GetWidgetController(const FWidgetControllerParams& WCParams)
{
	return nullptr;
}

void UWalkingHorrorUserWidget::InitController(APlayerController* PC)
{
    //	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetControllerClass);
	//OverlayWidget = Cast<UAuraUserWidget>(Widget);
}
*/