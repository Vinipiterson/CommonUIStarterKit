// Copyright Vinipi, 2025.

#include "UI/UISKCommonActivatableWidget.h"

#include "Input/CommonUIInputTypes.h"
#include "InputAction.h"

void UUISKCommonActivatableWidget::NativeDestruct()
{
	Super::NativeDestruct();

	UnregisterAllBindings();
}

TOptional<FUIInputConfig> UUISKCommonActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case ESKActivatableInputMode::GameAndMenu:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode, bHideCursorDuringViewportCapture);
	case ESKActivatableInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode, bHideCursorDuringViewportCapture);
	case ESKActivatableInputMode::Menu:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
	default:
		return TOptional<FUIInputConfig>();
	}
}

void UUISKCommonActivatableWidget::RegisterBinding(UInputAction* InputAction,
	const FOnInputActionExecutedDelegate& Callback, FSKInputActionBindingHandle& Handle)
{
	FBindUIActionArgs BindArgs(InputAction, FSimpleDelegate::CreateLambda([Callback]()
	{
	Callback.ExecuteIfBound();
	}));
	BindArgs.bDisplayInActionBar = true;
		
	Handle.Handle = RegisterUIActionBinding(BindArgs);
	BindedHandles.Add(Handle.Handle);
}

void UUISKCommonActivatableWidget::UnregisterBinding(FSKInputActionBindingHandle Handle)
{
	if (Handle.Handle.IsValid())
	{
		Handle.Handle.Unregister();
		BindedHandles.Remove(Handle.Handle);
	}
}

void UUISKCommonActivatableWidget::UnregisterAllBindings()
{
	for (auto& Handle : BindedHandles)
	{
		Handle.Unregister();
	}
	BindedHandles.Empty();
}
