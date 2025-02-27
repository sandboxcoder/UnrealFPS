// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZuonPickUpComponent.h"

UZuonPickUpComponent::UZuonPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UZuonPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UZuonPickUpComponent::OnSphereBeginOverlap);
}

void UZuonPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AZuonCharacter* Character = Cast<AZuonCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
