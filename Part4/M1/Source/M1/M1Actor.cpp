#include "M1Actor.h"

// Sets default values
AM1Actor::AM1Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AM1Actor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AM1Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

