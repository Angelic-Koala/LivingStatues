// ©Luc Wieler

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HoverableObject.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHoverableObject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LIVINGSTATUES_API IHoverableObject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
		virtual void OnHover() = 0;
		virtual void OffHover() = 0;
};
