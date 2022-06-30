// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class TIMEPOWER_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		ATimeManager();

		UFUNCTION(BlueprintCallable)
		float GetTimeFactor();

		// Time reverse control
		UFUNCTION(BlueprintCallable)
		void BeginTimeReverse();
		UFUNCTION(BlueprintCallable)
		void EndTimeReverse();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		// This is the current active factor of time
		UPROPERTY(BlueprintReadOnly)
		float CurrentTimeFactor = 1.0f;

	public:
		// Magic time values
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float NormalTimeFactor = 1.0f;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ReverseTimeFactor = -3.0f;
};
