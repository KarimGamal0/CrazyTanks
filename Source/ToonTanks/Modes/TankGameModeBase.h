// Karim Gamal Copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TankGameModeBase.generated.h"


class APawnTurret;
class APawnTank;
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;


	int32 GetTargetTurretsCount();
	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);

public:

	void ActorDied(AActor* DeadActor);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Loop")
		int32 StartDelay = 3;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
		void GameStart();
	UFUNCTION(BlueprintImplementableEvent)
		void GameOver(bool PlayerWon);
};
