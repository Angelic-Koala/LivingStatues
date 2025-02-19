// ©Luc Wieler


#include "Gamemodes/MainMenuGameMode.h"
#include "Components/Widget.h"
#include "Blueprint/UserWidget.h"


void AMainMenuGamemode::PostLogin(APlayerController* NewPlayer) {
    Super::PostLogin(NewPlayer);
    if (UWorld* World = GetWorld())
    {
        UUserWidget* MainMenu = CreateWidget<UUserWidget>(World, MainMenuWidget);
        MainMenu->AddToViewport();
        APlayerController* PlayerController = World->GetFirstPlayerController();
        if (PlayerController)
        {
            FInputModeUIOnly InputModeData;
            InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
            InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            PlayerController->SetInputMode(InputModeData);
            PlayerController->SetShowMouseCursor(true);
        }
    }
}

