// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCapsuleComponent;

UCLASS()
class TOONTANKS_API APawnBase : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpwanPoint;
public:
	// Sets default values for this pawn's properties
	APawnBase();
	
};
