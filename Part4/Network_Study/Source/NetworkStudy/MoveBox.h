#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveBox.generated.h"

UCLASS()
class NETWORKSTUDY_API AMoveBox : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveBox();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;
};
