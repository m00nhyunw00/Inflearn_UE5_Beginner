#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ColorBox.generated.h"

UCLASS()
class NETWORKSTUDY_API AColorBox : public AActor
{
	GENERATED_BODY()
	
public:	
	AColorBox();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
};
