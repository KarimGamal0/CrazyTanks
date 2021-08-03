// Karim Gamal Copyright

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRate = 2.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
		float FireRange = 500.0f;

	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	void CheckFireCondition();
	float ReturnDistanceToPlayer();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
