// ©Luc Wieler


#include "Gamestates/MyGameStateBase.h"
#include "Net/UnrealNetwork.h"


void AMyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(AMyGameStateBase, number);
}


void AMyGameStateBase::BeginPlay() {
    Super::BeginPlay();
}
