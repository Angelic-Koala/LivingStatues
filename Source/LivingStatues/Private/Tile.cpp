#include "Tile.h"


ATile::ATile()
{
    PrimaryActorTick.bCanEverTick = true;
    if (!RootComponent) RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Main Mesh"));
    MainMesh->SetupAttachment(RootComponent);
    HoverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hover Mesh"));
    HoverMesh->SetupAttachment(MainMesh);
}


void ATile::BeginPlay()
{
    Super::BeginPlay();

}

void ATile::OnHover(){
    HoverMesh->SetVisibility(true);
}

void ATile::OffHover(){
    HoverMesh->SetVisibility(false);
}


void ATile::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);


}
