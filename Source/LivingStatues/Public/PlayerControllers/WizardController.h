// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WizardController.generated.h"

/**
 * 
 */
UCLASS()
class LIVINGSTATUES_API AWizardController : public APlayerController
{
	GENERATED_BODY()
	public:
		AWizardController();

	protected:
		virtual void Tick(float DeltaTime) override;
		virtual void BeginPlay() override;

	private:
		FVector CachedDestination;
		class IHoverableObject* prevActor = nullptr;

};
