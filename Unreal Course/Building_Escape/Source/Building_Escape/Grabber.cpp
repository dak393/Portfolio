// Copyright Dakota G.

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	FindPhysicsHandle();

	SetupInputComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// DrawDebugGrabLine();
	if (!PhysicsHandle) {
		return;
	}
	if (PhysicsHandle->GrabbedComponent) {
		// Move the object we grabbed
		PhysicsHandle->SetTargetLocation(GetPlayerReach());
	}
}

// Checking for PhysicsHandle Component
void UGrabber::FindPhysicsHandle() {
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle) {
		UE_LOG(LogTemp, Error, TEXT("No Physics Handle Component attatched to %s"), *GetOwner()->GetName());
	}
}

void UGrabber::SetupInputComponent() {
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}

void UGrabber::Grab() {
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	AActor* ActorHit = HitResult.GetActor();

	// if we hit an object, attach the physics handle.
	if (ActorHit) {
		if (!PhysicsHandle) {
			return;
		}
		PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, GetPlayerReach());
	}
}

void UGrabber::Release() {
	if (!PhysicsHandle) {
		return;
	}
	PhysicsHandle->ReleaseComponent();
}

void UGrabber::DrawDebugGrabLine() {
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewLocation, OUT PlayerViewRotation);

	FVector LineTraceEnd = PlayerViewLocation + PlayerViewRotation.Vector() * Reach;
	// UE_LOG(LogTemp, Warning, TEXT("Position: %s \nRotation: %s" ), *ViewLocation.ToString(), *ViewRotation.ToString());

	DrawDebugLine(GetWorld(), PlayerViewLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.f, 0, 5.f);
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const {
	FHitResult Hit;
	// Ray-cast out for "reach"
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(OUT Hit, GetPlayerPos(), GetPlayerReach(), FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	return Hit;
}

FVector UGrabber::GetPlayerReach() const {
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewLocation, OUT PlayerViewRotation);

	return PlayerViewLocation + PlayerViewRotation.Vector() * Reach;
}

FVector UGrabber::GetPlayerPos() const {
	FVector PlayerViewLocation;
	FRotator PlayerViewRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewLocation, OUT PlayerViewRotation);

	return PlayerViewLocation;
}