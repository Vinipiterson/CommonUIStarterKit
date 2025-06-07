// Copyright Vinipi, 2025.

#pragma once

#include "CoreMinimal.h"
#include "GameUIManagerSubsystem.h"
#include "NativeGameplayTags.h"

#include "UISKGameUIManagerSubsystem.generated.h"

namespace UISKLayerTags
{
	COMMONUISTARTERKIT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Game)
	COMMONUISTARTERKIT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameMenu)
	COMMONUISTARTERKIT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Menu)
	COMMONUISTARTERKIT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Modal)
}

UCLASS()
class COMMONUISTARTERKIT_API UUISKGameUIManagerSubsystem : public UGameUIManagerSubsystem
{
	GENERATED_BODY()
};
