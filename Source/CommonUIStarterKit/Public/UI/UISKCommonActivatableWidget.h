// Copyright Vinipi, 2025.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UISKCommonActivatableWidget.generated.h"

class UInputAction;
DECLARE_DYNAMIC_DELEGATE(FOnInputActionExecutedDelegate);

UENUM(BlueprintType)
enum class ESKActivatableInputMode : uint8
{
	Menu,
	Game,
	GameAndMenu UMETA(DisplayName = "Game and Menu")
};

USTRUCT(BlueprintType)
struct FSKInputActionBindingHandle
{
	GENERATED_BODY()

	FUIActionBindingHandle Handle;
};

/**
 * Handles input and the action bar
 */
UCLASS(AutoExpandCategories = ("CommonUIStarterKit|Input"), PrioritizeCategories= ("CommonUIStarterKit"))
class COMMONUISTARTERKIT_API UUISKCommonActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

	//~UUserWidget
	virtual void NativeDestruct() override;
	//~UUserWidget
	
	//~UCommonActivatableWidget Interface
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
	//~UCommonActivatableWidget Interface
	
	//~Input
protected:
	UPROPERTY(EditDefaultsOnly, Category="CommonUIStarterKit|Input")
	ESKActivatableInputMode InputConfig = ESKActivatableInputMode::Menu;

	UPROPERTY(EditDefaultsOnly, Category="CommonUIStarterKit|Input", meta=(EditCondition="InputConfig != ESKActivatableInputMode::Menu", EditConditionHides))
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;

	UPROPERTY(EditAnywhere, Category="CommonUIStarterKit|Input", meta=(EditCondition="InputConfig != ESKActivatableInputMode::Menu", EditConditionHides))
	bool bHideCursorDuringViewportCapture = true;
	//~Input

	//~Action Bindings
private:
	TArray<FUIActionBindingHandle> BindedHandles;
	
public:
	UFUNCTION(BlueprintCallable, Category="CommonUIStarterKit|Input")
	void RegisterBinding(UInputAction* InputAction, const FOnInputActionExecutedDelegate& Callback, FSKInputActionBindingHandle& Handle);

	UFUNCTION(BlueprintCallable, Category="CommonUIStarterKit|Input")
	void UnregisterBinding(FSKInputActionBindingHandle Handle);

	UFUNCTION(BlueprintCallable, Category="CommonUIStarterKit|Input")
	void UnregisterAllBindings();
	//~Action Bindings
};
