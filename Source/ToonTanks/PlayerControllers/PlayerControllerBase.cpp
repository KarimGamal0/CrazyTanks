// Karim Gamal Copyright


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnabled)
{
	if (SetPlayerEnabled) 
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}

	bShowMouseCursor = SetPlayerEnabled;
}