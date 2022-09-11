// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageTakingEntity.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UDamageTakingEntity : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class STORMLINK_API IDamageTakingEntity
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Damage")
	void TakeDamage(AActor* SourceActor, AActor* Instigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category= "Damage")
	bool IsCanTakeDamage();
	virtual bool IsCanTakeDamage_Implementation();
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
