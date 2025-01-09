// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set starting position to (0, 0)
	Start = FVector2D(0, 0);
	CurrentPosition = Start;

	// Reset number of movement
	MoveCount = 0;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// Output Log
	UE_LOG(LogTemp, Warning, TEXT("Actor Spawned at Position: (%f, %f)"), Start.X, Start.Y);
	
	// Call out Move function
	Move();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Step: return distance of x, y movement
int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

// Move: 10 times movement and output log
void AMyActor::Move()
{
	for (int32 i = 0; i < 10; ++i)
	{
		// culculate distance of x, y movement
		int32 StepX = Step();
		int32 StepY = Step();

		// Culculate a new position
		CurrentPosition.X += StepX;
		CurrentPosition.Y += StepY;

		// Output log
		UE_LOG(LogTemp, Warning, TEXT("Step %d: Moved to Position (%f, %f)"), i + 1, CurrentPosition.X, CurrentPosition.Y);

	}
	// Output final position
	UE_LOG(LogTemp, Warning, TEXT("Final Position: (%f, %f)"), CurrentPosition.X, CurrentPosition.Y);

}
