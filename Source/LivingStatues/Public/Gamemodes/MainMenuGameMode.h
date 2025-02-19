// ©Luc Wieler

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

class UUserWidget;
/**
 *
 */
UCLASS()
class LIVINGSTATUES_API AMainMenuGamemode : public AGameModeBase
{
    GENERATED_BODY()
    
    public:


    protected:
        virtual void PostLogin(APlayerController* NewPlayer) override;


    private:
        UPROPERTY(EditAnywhere, Category = "UI", meta = (AllowPrivateAccess = "true"))
        TSubclassOf<UUserWidget> MainMenuWidget;

    
};

