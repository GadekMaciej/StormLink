// Fill out your copyright notice in the Description page of Project Settings.


#include "SLProjectileSpawnComponent.h"

// Sets default values for this component's properties
USLProjectileSpawnComponent::USLProjectileSpawnComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USLProjectileSpawnComponent::InitializeComponent()
{
	Super::InitializeComponent();

	// there are no plans of adding weapons/guns and this component theoretically should only appear on pawns
	check(Cast<APawn>(GetOwner()))
}


// Called when the game starts
void USLProjectileSpawnComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USLProjectileSpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

ASLProjectileBase* USLProjectileSpawnComponent::SpawnProjectile(const FVector& Location, const FRotator& Rotation, TSubclassOf<ASLProjectileBase> ProjectileOverrideClass)
{
	TSubclassOf<ASLProjectileBase> ClassToSpawn = SpawnedProjectileClass;
	if (!SpawnedProjectileClass)
	{
		return nullptr;
	}

	UWorld* world = GetWorld();
	
	if (!world)
	{
		return nullptr;
	}

	if (ProjectileOverrideClass)
	{
		ClassToSpawn = ProjectileOverrideClass;
	}
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetOwner();

	// we should cache the result instead of casting everytime - but this is temporary anyways, until we add guns
	SpawnParams.Instigator = CastChecked<APawn>(GetOwner());

	ASLProjectileBase* SpawnedProjectile = CastChecked<ASLProjectileBase>(world->SpawnActor(ClassToSpawn, &Location, &Rotation, SpawnParams));
	return SpawnedProjectile;
}

