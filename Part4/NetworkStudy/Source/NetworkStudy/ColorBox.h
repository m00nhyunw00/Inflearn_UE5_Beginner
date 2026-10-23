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
	
protected:
	// UPROPERTY(Replicated)
	// int32 Counter = 0;
	
	// 서버 값 복제 → 클라이언트에서 OnRep_Counter 호출
	UPROPERTY(ReplicatedUsing = OnRep_Counter)
	int32 Counter = 0;
	
	UFUNCTION()
	void OnRep_Counter();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	// Reliable: 유실 시 재전송
	// 서버 호출 → 서버와 관련 클라이언트에서 실행
	UFUNCTION(NetMulticast, Reliable)
	void MulticastRPC();
	
	// UFUNCTION(Server, Reliable)
	// void ServerRPC();
	
	// 소유 클라이언트의 요청 → 서버에서 검증 후 실행
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRPC(int32 AddHealth);
	
	// 서버 호출 → 소유 클라이언트에서 실행
	UFUNCTION(Client, Reliable)
	void ClientRPC();
};
