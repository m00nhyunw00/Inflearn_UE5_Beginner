#include "ColorBox.h"

#include "Net/UnrealNetwork.h"

AColorBox::AColorBox()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

void AColorBox::BeginPlay()
{
	Super::BeginPlay();
	
	// 액터 복제 활성화
	SetReplicates(true);
	
	// 서버에서만 값 설정
	if (HasAuthority())
	{
		Counter = FMath::RandRange(0, 1000);
		// C++에서는 서버의 OnRep를 직접 호출
		OnRep_Counter();
	}
}

void AColorBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AColorBox::OnRep_Counter()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("%d"), Counter));
}

void AColorBox::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// UPROPERTY 지정과 함께 이 등록도 필요하다. 값은 서버에서 클라이언트로 복제된다.
	// Counter를 복제 대상에 등록
	DOREPLIFETIME(AColorBox, Counter);
}

void AColorBox::ClientRPC_Implementation()
{
}

bool AColorBox::ServerRPC_Validate(int32 AddHealth)
{
	// 100000 이상이면 검증 실패 → 요청 클라이언트 연결 종료
	if (AddHealth >= 100000)
	{
		return false;
	}
	
	return true;
}

void AColorBox::ServerRPC_Implementation(int32 AddHealth)
{
}

void AColorBox::MulticastRPC_Implementation()
{
	
}

