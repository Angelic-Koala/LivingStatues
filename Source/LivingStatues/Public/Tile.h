#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HoverableObject.h"

#include "Tile.generated.h"


UCLASS()
class LIVINGSTATUES_API ATile : public AActor, public IHoverableObject
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATile();
    virtual void OnHover() override;
    virtual void OffHover() override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;


private:
    // Called every frame

    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* MainMesh;


    UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* HoverMesh;

    FVector Cords;
public:
    FORCEINLINE FVector GetCoordinates() const { return Cords; }
};
