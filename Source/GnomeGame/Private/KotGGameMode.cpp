// Fill out your copyright notice in the Description page of Project Settings.

#include "KotGGameMode.h"

//Single round game mode
//Fight over crown
//Drop crown on death
//Respawn after 5 seconds
//Winner - held crown longest after 3mins

UFUNCTION(BlueprintCallable, Category = "KotG")
void AKotGGameMode::GameSetUp(ASpawner *spawner)
{
	//Spawn players
	spawner->KotGSpawnAllPlayers();
	//Spawn crown
	spawner->KotGSpawnCrown();
}

UFUNCTION(BlueprintCallable, Category = "KotG")
void AKotGGameMode::OnGameStart()
{
	//Start timer
	GetWorld()->GetTimerManager().SetTimer(GameTimerHandle, this, &AKotGGameMode::OnTimerEnd, 180, false);
	//Display timer
	DisplayTimer();
}

UFUNCTION(BlueprintCallable, Category = "KotG")
void AKotGGameMode::OnCrownPickup(AGnome *player, ASpawner *spawner)
{
	//Mark player as having crown
	player->KotGSetHasCrown(true);
	//Despawn crown
	spawner->KotGDespawnCrown();
	//Give player points
	player->KotGStartGivingPoints();
}

UFUNCTION(BlueprintCallable, Category = "KotG")
void AKotGGameMode::OnPlayerDeath(AGnome *player, ASpawner *spawner)
{
	//Stop giving points
	player->KotGStopGivingPoints();
	//Spawn crown at death position
	spawner->KotGSpawnCrown();
	//Despawn player
	spawner->KotGDespawnPlayer(player->GetPlayerID());
	//Wait 5 seconds
	//...
	//Respawn player
	spawner->KotGSpawnPlayer(player->GetPlayerID());
}

UFUNCTION()
void AKotGGameMode::OnTimerEnd()
{
	//Stop game
	//...
	//Declare winner
	DisplayWinner();
	//Display points
	DisplayPoints();
}