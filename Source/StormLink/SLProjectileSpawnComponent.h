// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SLProjectileBase.h"
#include "SLProjectileSpawnComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=(Projectile), meta=(BlueprintSpawnableComponent) )
class STORMLINK_API USLProjectileSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USLProjectileSpawnComponent();

	virtual void InitializeComponent() override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	* @return if success
	*/
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	ASLProjectileBase* SpawnProjectile(const FVector& Location, const FRotator& Rotation, TSubclassOf<ASLProjectileBase> ProjectileOverrideClass);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile", meta=(AllowPrivateAccess="true"))
	TSubclassOf<ASLProjectileBase> SpawnedProjectileClass;
};
