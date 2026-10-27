#include "MoveBox.h"

AMoveBox::AMoveBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AMoveBox::BeginPlay()
{
	Super::BeginPlay();
	
	SetReplicates(true);
	SetReplicateMovement(true);
}

void AMoveBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector Offset = GetActorForwardVector() * DeltaTime * 1000.f;
		AddActorWorldOffset(Offset, true);
	}
}

