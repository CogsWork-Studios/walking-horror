// Fill out your copyright notice in the Description page of Project Settings.


#include "WalkingHorrorHUD.h"
#include "WalkingHorrorWidgetController.h"
#include "WalkingHorrorUserWidget.h"
/*

#include "UI/Widgets/AuraUserWidget.h"
#include "UI/Widgets/OverlayWidgetController.h"
*/

UWalkingHorrorWidgetController* AWalkingHorrorHUD::GetWidgetController(const FWidgetControllerParams& WCParams)
{
	if (WidgetController == nullptr)
	{

		WidgetController = NewObject<UWalkingHorrorWidgetController>(this, WidgetControllerClass);
		WidgetController->SetWidgetControllerParams(WCParams);
		//WidgetController->BindCallbacksToDependencies();

		return WidgetController;
	}
	return WidgetController;
}

void AWalkingHorrorHUD::InitController(APlayerController* PC)
{
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), UserWidgetClass);
	MenuWidget = Cast<UWalkingHorrorUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC);
	UWalkingHorrorWidgetController* MainMenuWidgetController = GetWidgetController(WidgetControllerParams);
	MenuWidget->SetWidgetController(WidgetController);

	/*/
	


	WidgetController->BroadcastInitialValues();

	Widget->AddToViewport();*/
}




