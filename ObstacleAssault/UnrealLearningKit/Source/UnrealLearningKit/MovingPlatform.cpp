#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(const float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + PlatformVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);
	const float DistMoved = FVector::Dist(StartLocation, CurrentLocation);
	// Reverse direction of motion if gone too far
	if(DistMoved > MovedDistance)
	{
		const FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime) const
{
	UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());
}

