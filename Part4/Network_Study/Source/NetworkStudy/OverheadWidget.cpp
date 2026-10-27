#include "OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString Text)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(Text));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* Pawn)
{
	ENetRole LocalRole = Pawn->GetLocalRole();
	ENetRole RemoteRole = Pawn->GetRemoteRole();
	
	FString LocalRoleStr;
	FString RemoteRoleStr;
	
	switch (LocalRole)
	{
	case ENetRole::ROLE_Authority:	// 서버
		LocalRoleStr = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:	// 클라이언트
		LocalRoleStr = FString("Autonomous");
		break;
	case ENetRole::ROLE_SimulatedProxy:		// 나를 제외한 클라이언트
		LocalRoleStr = FString("Simulated");
		break;
	}

	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:	// 서버
		RemoteRoleStr = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:	// 클라이언트
		RemoteRoleStr = FString("Autonomous");
		break;
	case ENetRole::ROLE_SimulatedProxy:		// 나를 제외한 클라이언트
		RemoteRoleStr = FString("Simulated");
		break;
	}
	
	FString ResultStr = FString::Printf(TEXT("Local : %s\n Remote : %s"), *LocalRoleStr, *RemoteRoleStr);
	SetDisplayText(ResultStr);
}
