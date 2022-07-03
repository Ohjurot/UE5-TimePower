// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATimeManager::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
	// Store recorded time
	if (TimeReversalAbilityEnabled)
    {
        CurrentRecordedTime = TMathUtil<float>::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaSeconds * CurrentTimeFactor);
        if (CurrentRecordedTime <= 0.0f)
        {
            EndTimeReverse();
            CurrentRecordedTime = 0.0f;
        }
	}
}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

bool ATimeManager::GetAbilityAvailible()
{
	return TimeReversalAbilityEnabled && CurrentRecordedTime >= ReverseTimeThreshold;
}

float ATimeManager::GetCurrentReversableTime()
{
	return CurrentRecordedTime;
}

void ATimeManager::BeginTimeReverse()
{
	if (GetAbilityAvailible())
	{
		CurrentTimeFactor = ReverseTimeFactor;
	}
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

void ATimeManager::EnableTimeReverseAbility()
{
	if (!TimeReversalAbilityEnabled)
	{
		TimeReversalAbilityEnabled = true;
	}
}

void ATimeManager::DisableTimeReverseAbility()
{
	if (TimeReversalAbilityEnabled)
	{
		EndTimeReverse();
		CurrentRecordedTime = 0.0f;
		TimeReversalAbilityEnabled = false;
	}
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Apply normal time
	CurrentTimeFactor = NormalTimeFactor;
}
