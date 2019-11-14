// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Pawn.h"
#include "Gnome.generated.h"

UCLASS()
class GNOMEGAME_API AGnome : public APawn
{
	GENERATED_BODY()
	
	private:
		FTimerHandle KotGPointsTimerHandle;
		UPROPERTY(EditAnywhere, Category = "Player")
			int playerID;
		UPROPERTY(VisibleAnywhere, Category = "KotG")
			bool KotGHasCrown = false;
		UPROPERTY(VisibleAnywhere, Category = "KotG")
			int KotGPoints = 0;

	public:
		int GetPlayerID() { return playerID; };
		void KotGSetHasCrown(bool hasCrown) { KotGHasCrown = hasCrown; };
		void KotGStartGivingPoints();
		void KotGStopGivingPoints();
		UFUNCTION()
			void KotGGivePoints();
};
