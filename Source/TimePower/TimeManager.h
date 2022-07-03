// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MathUtil.h"
#include "GameFramework/Actor.h"

#include "TimeManager.generated.h"

UCLASS()
class TIMEPOWER_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		ATimeManager();

		// Actor tick
		void Tick(float DeltaSeconds) override;

	public:
		// Helper getters
		UFUNCTION(BlueprintCallable)
		float GetTimeFactor();
		UFUNCTION(BlueprintCallable)
		bool GetAbilityAvailible();
		UFUNCTION(BlueprintCallable)
		float GetCurrentReversableTime();


		// Time reverse control
		UFUNCTION(BlueprintCallable)
		void BeginTimeReverse();
		UFUNCTION(BlueprintCallable)
		void EndTimeReverse();

		// Enable control
		UFUNCTION(BlueprintCallable)
		void EnableTimeReverseAbility();
		UFUNCTION(BlueprintCallable)
		void DisableTimeReverseAbility();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	protected:
		// Current state of ability
		UPROPERTY(BlueprintReadOnly)
		float CurrentTimeFactor = 1.0f;
		UPROPERTY(BlueprintReadOnly)
		float CurrentRecordedTime = 0.0f;

		// State helpers
		UPROPERTY(BlueprintReadOnly)
		bool TimeReversalAbilityEnabled = false;

	public:
		// Global ability preset
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float NormalTimeFactor = 1.0f;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ReverseTimeFactor = -3.0f;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ReverseTimeThreshold = 3.0f;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ReverseTimeMaximum = 15.0f;

};
