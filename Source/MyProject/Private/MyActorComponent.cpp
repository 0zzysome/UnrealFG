// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values for this component's properties
UMyActorComponent::UMyActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
	const auto Owner = GetOwner();
	Origin = Owner->GetActorLocation();
	Destination = Origin;
	// adds z hight to destinmation 
	Destination.Z += HeightMax;
	// ...
	
}


// Called every frame
void UMyActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const auto Owner = GetOwner();

	
	Time += DeltaTime; 
	//normalize
	const auto T = Time / Duration;
	const auto NewPosition = UKismetMathLibrary::VLerp(Origin, Destination, T);
	Owner->SetActorLocation(NewPosition);
	if(Time >= Duration)
	{
		Time -= Duration;
		// flips origin and destination
		const auto temp = Origin;
		Origin = Destination;
		Destination = temp;
	}
	// ...
}

