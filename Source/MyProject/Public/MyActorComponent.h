// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()
	float Time;
	FVector Origin;
	FVector Destination;
public:	
	// Sets default values for this component's properties
	UMyActorComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HeightMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Duration;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

	
};
