// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/GameModeBase.h"
#include "Gnome.h"
#include "Spawner.h"
#include "KotGGameMode.generated.h"

/**
 * 
 */

 //Single round game mode
 //Fight over crown
 //Drop crown on death
 //Respawn after 5 seconds
 //Winner - held crown longest after 3mins

UCLASS()
class GNOMEGAME_API AKotGGameMode : public AGameModeBase
{
	GENERATED_BODY()

	private:
		FTimerHandle GameTimerHandle;

	public:
		UFUNCTION(BlueprintCallable, Category = "KotG")
			void GameSetUp(ASpawner *spawner);
		UFUNCTION(BlueprintCallable, Category = "KotG")
			void OnGameStart();
		UFUNCTION(BlueprintCallable, Category = "KotG")
			void OnCrownPickup(AGnome *player, ASpawner *spawner);
		UFUNCTION(BlueprintCallable, Category = "KotG")
			void OnPlayerDeath(AGnome *player, ASpawner *spawner);
		UFUNCTION()
			void OnTimerEnd();
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void DisplayTimer();
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void DisplayWinner();
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void DisplayPoints();
};
