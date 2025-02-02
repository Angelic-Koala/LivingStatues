// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllers/WizardController.h"
#include "Tile.h"
#include "DrawDebugHelpers.h"

AWizardController::AWizardController(){
    CachedDestination = FVector::ZeroVector;
    
}

void AWizardController::BeginPlay(){
    Super::BeginPlay();
    bShowMouseCursor = true;
    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);  // Ensure cursor stays visible
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    SetInputMode(InputMode);
}

void AWizardController::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    FHitResult Hit;
	
    
    if (GetHitResultUnderCursor(ECC_GameTraceChannel1, true, Hit))
	{
        DrawDebugSphere(
            GetWorld(),          // The world context
            Hit.GetActor()->GetActorLocation(),    // Center of the sphere
            100.0f,              // Radius of the sphere
            12,                  // Number of segments
            FColor::Red,         // Color of the sphere
            false,                // Persistent (remains after one frame)
            1.0f,                // Duration (0 = forever)
            0,                   // Depth priority
            1.0f                 // Thickness of lines
        );
        
        IHoverableObject* actor = Cast<IHoverableObject>(Hit.GetActor());
		if(actor != nullptr){
            if(prevActor != actor && prevActor != nullptr) prevActor->OffHover();
            prevActor = actor;
            actor->OnHover();
        }
	}
    else{
        if(prevActor != nullptr) prevActor->OffHover();
    }
}