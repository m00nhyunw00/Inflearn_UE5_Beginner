#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetDisplayText(FString Text);
	
	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* Pawn);
	
public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* DisplayText;
};
