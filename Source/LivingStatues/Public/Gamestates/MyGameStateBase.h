// ©Luc Wieler

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class LIVINGSTATUES_API AMyGameStateBase : public AGameStateBase
{
    GENERATED_BODY()
public:
    UPROPERTY(Replicated)
    int number = 0;
protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void BeginPlay() override;
};

