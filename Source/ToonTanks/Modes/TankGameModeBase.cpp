// Karim Gamal Copyright


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}


void ATankGameModeBase::HandleGameStart()
{
	TargetTurrets = GetTargetTurretsCount();
	PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	GameOver(PlayerWon);
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerTank)
	{
		PlayerTank->HandleDestruction();
		HandleGameOver(false);
	}
	else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();

		if(--TargetTurrets == 0)
		{
			HandleGameOver(true);
		}
	}
}

int32 ATankGameModeBase::GetTargetTurretsCount()
{
	TArray<AActor*> TurretActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), TurretActors);
	return TurretActors.Num();
}
