// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Runtime/Engine/Classes/Components/InstancedStaticMeshComponent.h>
#include "../../Intermediate/ProjectFiles/CloudPoint.h"
#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewPoint.generated.h"


UCLASS()
class LIGHTS_API ANewPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewPoint();

	std::vector<CloudPoint> nextState;

	float totalTime;

	int state;

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* InstancedStaticMeshComponent;

	UPROPERTY(Transient)
	TArray<FTransform> Transforms;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int getSign(float initialValue, float finalValue);

	float getAbsDiff(float initialValue, float finalValue);

};
