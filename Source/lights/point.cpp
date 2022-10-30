// Fill out your copyright notice in the Description page of Project Settings.


#include "point.h"

// Sets default values
Apoint::Apoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PointAppearance = CreateDefaultSubobject<UPaperSpriteComponent>("PointAppearance");
}

// Called when the game starts or when spawned
void Apoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Apoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	float LO = -1.f;
	float HI = 1.f;
	float RandX = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	float RandY = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	float RandZ = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
	CurrentLocation.X += RandX;
	CurrentLocation.Y += RandY;
	CurrentLocation.Z += RandZ;
	SetActorLocation(CurrentLocation);
}

