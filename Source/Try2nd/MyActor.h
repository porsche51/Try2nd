// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class TRY2ND_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Starting Location
	FVector2D Start;
	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Distance of one step
	int32 Step();

	// Logic of total movement
	void Move();

private:
	// Current Location
	FVector2D CurrentPosition;

	// Number of Movement
	int32 MoveCount;

};
