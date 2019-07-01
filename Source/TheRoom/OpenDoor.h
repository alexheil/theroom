// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEROOM_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenDoor();
	void CloseDoor();

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime;

	// Returns total mass in kilo
	float GetTotalMassOfActorsOnPlate();

	AActor* Owner = nullptr; // The Owning door.
};
