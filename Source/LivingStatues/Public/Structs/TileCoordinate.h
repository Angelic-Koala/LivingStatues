// ©Luc Wieler

#pragma once

#include "CoreMinimal.h"
#include "TileCoordinate.generated.h"

USTRUCT(BlueprintType)
struct FTileCoordinate{
	GENERATED_BODY()
	public: 
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float X;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			float Y;

		FTileCoordinate(): X(0), Y(0) // constructor
		{
			
		}
};
/**
 * 
 */
class LIVINGSTATUES_API TileCoordinate
{
public:
	TileCoordinate();
	~TileCoordinate();
};
