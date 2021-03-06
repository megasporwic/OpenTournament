// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "GameFramework/Actor.h"
#include "UR_Character.h"
#include "Engine.h"
#include "Engine/Canvas.h" // for FCanvasIcon

#include "UR_Ammo.generated.h"

UCLASS()
class OPENTOURNAMENT_API AUR_Ammo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUR_Ammo(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere)
	UShapeComponent* Tbox;

	UPROPERTY(EditAnywhere)
	UAudioComponent* Sound;

	UPROPERTY(EditAnywhere)
	FString AmmoName = FString(TEXT(""));

	UPROPERTY(EditAnywhere)
	AUR_Character* PlayerController;

	bool bItemIsWithinRange = false;

	void Pickup();

	void GetPlayer(AActor* Player);

	UPROPERTY(EditAnywhere)
	int32 amount;


	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SM_TBox;
	UFUNCTION()
		void OnTriggerEnter(class UPrimitiveComponent* HitComp, class AActor* Other, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnTriggerExit(class UPrimitiveComponent* HitComp, class AActor* Other, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** weapon mesh: 3rd person view */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		UStaticMeshComponent* AmmoMesh;

	/** Returns Mesh3P subobject **/
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return AmmoMesh; }

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
