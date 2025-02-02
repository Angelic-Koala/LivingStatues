#include "Pawns/Wizard.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"
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
    DesiredZoom = SpringArm->TargetArmLength;
    wizard = this;
}


void AWizard::ScreenMovementActionCall(const FInputActionValue& Value)
{
    //Debug
        if (GEngine)
        {
            FString ConvertedMessage = FString("Recording Screen");
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ConvertedMessage);
        }

    //Screen Movement
        FVector Location = wizard->GetActorTransform().GetLocation();
        double XDiff = Value.Get<FVector2D>().X * ScreenMovementSensitivity * (1 + SpringArm->TargetArmLength / 1000);
        double YDiff = Value.Get<FVector2D>().Y * -1 * ScreenMovementSensitivity * (1 + SpringArm->TargetArmLength / 1000);
        FVector NewLocation = FVector(Location.X + XDiff, Location.Y + YDiff, Location.Z);
        wizard->SetActorLocation(NewLocation);


}

void AWizard::ZoomActionCall(const struct FInputActionValue& Value){
    float ZoomAxisValue = Value.Get<float>();
    DesiredZoom = FMath::Clamp(DesiredZoom + (ZoomAxisValue * ZoomStep), 300, 5000);
    
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
    PlayerController = Cast<APlayerController>(Controller);
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
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
    //Camera Movement
        SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredZoom, DeltaTime, 5);

    //Hovering Object
        FHitResult Hit;
        PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
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
        EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ThisClass::ZoomActionCall);
    }
}
