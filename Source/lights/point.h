// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "point.generated.h"

UCLASS()
class LIGHTS_API Apoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Apoint();

	UPROPERTY(EditAnywhere, Category = "Components")
	UPaperSpriteComponent* PointAppearance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
