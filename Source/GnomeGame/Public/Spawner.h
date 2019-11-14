// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class GNOMEGAME_API ASpawner : public AActor
{
	GENERATED_BODY()
	
	public:
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void KotGSpawnAllPlayers();
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void KotGSpawnPlayer(int playerID);
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void KotGDespawnPlayer(int playerID);
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void KotGSpawnCrown();
		UFUNCTION(BlueprintImplementableEvent, Category = "KotG")
			void KotGDespawnCrown();
};
