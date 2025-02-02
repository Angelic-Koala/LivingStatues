#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Wizard.generated.h"


UCLASS()
class LIVINGSTATUES_API AWizard : public APawn
{
    GENERATED_BODY()


public:
    // Sets default values for this pawn's properties
    AWizard();





    void ScreenMovementActionCall(const struct FInputActionValue& Value);
    void ClickActionCall();
    void SpellActionCall();
    void RightClickActionCall();
    void ZoomActionCall(const struct FInputActionValue& Value);


protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

    //Input
        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputMappingContext* DefaultMappingContext;


        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputAction* ScreenMovementAction;


        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputAction* ZoomAction;


        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputAction* ClickAction;


        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputAction* SpellAction;


        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        class UInputAction* RightClickAction;

    //Field
        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        float ZoomStep = 30.0f;

        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        float DesiredZoom;

        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        float ScreenMovementSensitivity = 15.0f;

        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
        float Health = 150.0f;


    //Components
        AWizard* wizard;

        class APlayerController* PlayerController;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
        class USpringArmComponent* SpringArm;

        UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
        class UCameraComponent* CameraComponent;

};

