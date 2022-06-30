// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

void ATimeManager::BeginTimeReverse()
{
	CurrentTimeFactor = ReverseTimeFactor;
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Apply normal time
	CurrentTimeFactor = NormalTimeFactor;
}
