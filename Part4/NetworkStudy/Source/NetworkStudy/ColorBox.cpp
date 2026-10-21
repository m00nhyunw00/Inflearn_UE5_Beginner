#include "ColorBox.h"

AColorBox::AColorBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

void AColorBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void AColorBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

