// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeReversalGameMode.h"

void ATimeReversalGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);
    
    // Init the time manager
    TimeManager = Cast<ATimeManager>(GetWorld()->SpawnActor(ATimeManager::StaticClass()));
    if (!TimeManager)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create TimeManager!"));
    }
}


ATimeManager* ATimeReversalGameMode::GetTimeManager()
{
    // Check that time manger is valid
    if (!TimeManager)
    {
        UE_LOG(LogTemp, Error, TEXT("Tried to call GetTimeManager() bevore it existed"));
    }

    return TimeManager;
}
