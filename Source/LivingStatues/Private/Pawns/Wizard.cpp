#include "Pawns/Wizard.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
AWizard::AWizard()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    if (!RootComponent) RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArm);
}


void AWizard::ScreenMovementActionCall(const FInputActionValue& Value)
{
    if (GEngine)
    {
        FString ConvertedMessage = FString("Recording Screen");
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ConvertedMessage);
    }
}


void AWizard::ClickActionCall()
{
    if (GEngine)
    {
        FString ConvertedMessage = FString("Left Clicked");
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ConvertedMessage);
    }
}


void AWizard::SpellActionCall()
{
    if (GEngine)
    {
        FString ConvertedMessage = FString("Used Spell");
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ConvertedMessage);
    }
}


void AWizard::RightClickActionCall()
{
    if (GEngine)
    {
        FString ConvertedMessage = FString("Right Clicked");
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ConvertedMessage);
    }
}


void AWizard::BeginPlay()
{
    Super::BeginPlay();
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
        // FInputModeGameAndUI InputMode;
        // InputMode.SetHideCursorDuringCapture(false);
        // InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
        // InputMode.SetWidgetToFocus(nullptr); // Allow for input to pass through
        // PlayerController->SetInputMode(InputMode);
        // PlayerController->bShowMouseCursor = true; // Show the mouse cursor
        // CurrentZoomTarget = SpringArm->TargetArmLength;
    }

}


// Called every frame
void AWizard::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


}


// Called to bind functionality to input
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);


    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(ClickAction, ETriggerEvent::Triggered, this, &ThisClass::ClickActionCall);
        EnhancedInputComponent->BindAction(SpellAction, ETriggerEvent::Triggered, this, &ThisClass::SpellActionCall);
        EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Triggered, this, &ThisClass::RightClickActionCall);
        EnhancedInputComponent->BindAction(ScreenMovementAction, ETriggerEvent::Triggered, this, &ThisClass::ScreenMovementActionCall);
    }
}
