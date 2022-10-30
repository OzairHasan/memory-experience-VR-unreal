// Fill out your copyright notice in the Description page of Project Settings.


#include "NewPoint.h"
#include "../../Intermediate/ProjectFiles/PointCloudGenerator.cpp"
#include <string>
#include "../../Intermediate/ProjectFiles/CloudPoint.h"
#include <vector>
#include "../../Intermediate/ProjectFiles/CloudPoint.cpp"
#include "../../Intermediate/ProjectFiles/FileReader.cpp"

//#include <Runtime/Engine/Classes/Components/InstancedStaticMeshComponent.h>

// Sets default values
ANewPoint::ANewPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InstancedStaticMeshComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
	SetRootComponent(InstancedStaticMeshComponent);
	//InstancedStaticMeshComponent->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	//InstancedStaticMeshComponent->SetGeneratorOverlapEvents(false);
	totalTime = 0.f;
	state = 0;
	std::string filePath = "C:/Users/ozair/Downloads/cloud_point_rescaling/fontanaM_50k.txt";
	PointCloudGenerator cpg = PointCloudGenerator();
	nextState = cpg.getPointCloud(filePath);
	for (int i{ 0 }; i < 416; ++i) {
		nextState.pop_back();
	}
}

// Called when the game starts or when spawned
void ANewPoint::BeginPlay()
{
	Super::BeginPlay();

	if (InstancedStaticMeshComponent->GetInstanceCount() == 0) {
		
		std::string filePath = "C:/Users/ozair/Downloads/cloud_point_rescaling/plafondbleu_50k.txt";
		PointCloudGenerator cpg = PointCloudGenerator();
		std::vector<CloudPoint> points = cpg.getPointCloud(filePath);
		//Transforms.Empty(points.size());
		for (auto point : points) {
			FVector const Location = FVector(point.getX() * 10000, point.getY() * 10000, point.getZ() * 10000);
			//Transforms.Add(FTransform(Location));
			//FRotator const Rotation = FRotator(0.f, 0.f, 80.f);
			//World->SpawnActor<Apoint>(PointBP, Location, Rotation);
			InstancedStaticMeshComponent->AddInstance(FTransform(Location));
		}
	}
}

int ANewPoint::getSign(float initialValue, float finalValue) {
	if (finalValue >= initialValue) {
		return 1;
	}
	return -1;
}

float ANewPoint::getAbsDiff(float initialValue, float finalValue) {
	return std::abs(finalValue - initialValue);
}

// Called every frame
void ANewPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	totalTime += DeltaTime;
	int Instances = InstancedStaticMeshComponent->GetInstanceCount();
	/*float LO = -30.f;
	float HI = 30.f;
	for (int i{ 0 }; i < Instances; ++i) {
		float RandX = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		float RandY = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		float RandZ = LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
		FTransform CurrentInstanceTransform;
		InstancedStaticMeshComponent->GetInstanceTransform(i, CurrentInstanceTransform);
		CurrentInstanceTransform.AddToTranslation(FVector(RandX, RandY, RandZ));
		InstancedStaticMeshComponent->UpdateInstanceTransform(i, CurrentInstanceTransform);
	}*/

	if (totalTime <= 10.f) {
		return;
	}

	if (state == 1) {
		return;
	}
	float step = 0.05;//300;
	float boundary = 300;
	int allMoveCheck = 0;
	for (int i{ 0 }; i < Instances; ++i) {
		int pointMoveCheck = 0;
		FTransform CurrentInstanceTransform;
		InstancedStaticMeshComponent->GetInstanceTransform(i, CurrentInstanceTransform);
		float finalX = nextState[i].getX() * 10000;
		float finalY = nextState[i].getY() * 10000;
		float finalZ = nextState[i].getZ() * 10000;
		float currentX = CurrentInstanceTransform.GetTranslation().X;
		float currentY = CurrentInstanceTransform.GetTranslation().Y;
		float currentZ = CurrentInstanceTransform.GetTranslation().Z;
		float deltaX = currentX + getSign(currentX, finalX) * getAbsDiff(currentX, finalX) * step;
		float deltaY = currentY + getSign(currentY, finalY) * getAbsDiff(currentY, finalY) * step;
		float deltaZ = currentZ + getSign(currentZ, finalZ) * getAbsDiff(currentZ, finalZ) * step;
		if (std::abs(finalX - currentX) <= boundary) {
			deltaX = finalX; pointMoveCheck++;
		}
		if (std::abs(finalY - currentY) <= boundary) {
			deltaY = finalY; pointMoveCheck++;
		}
		if (std::abs(finalZ - currentZ) <= boundary) {
			deltaZ = finalZ; pointMoveCheck++;
		}
		if (pointMoveCheck == 3) {
			allMoveCheck++;
		}
		InstancedStaticMeshComponent->UpdateInstanceTransform(i,
			FTransform(FVector(deltaX, deltaY, deltaZ)));
	}
	InstancedStaticMeshComponent->MarkRenderStateDirty();

	if (allMoveCheck < Instances) {
		return;
	}
	state = 1;
}

