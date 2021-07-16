// Karim Gamal Copyright

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

class UProjectileMovementComponent;
UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileBase;
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		TSubclassOf<UDamageType> DamageType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = "true"))
		float MovementSpeed = 1300;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage", meta = (AllowPrivateAccess = "true"))
		float Damage = 50;

public:
	// Sets default values for this actor's properties
	AProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};