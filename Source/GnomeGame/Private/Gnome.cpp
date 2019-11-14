// Fill out your copyright notice in the Description page of Project Settings.

#include "Gnome.h"

void AGnome::KotGStartGivingPoints()
{
	GetWorld()->GetTimerManager().SetTimer(KotGPointsTimerHandle, this, &AGnome::KotGGivePoints, 1, true);
}

void AGnome::KotGStopGivingPoints()
{
	GetWorld()->GetTimerManager().ClearTimer(KotGPointsTimerHandle);
}

UFUNCTION()
void AGnome::KotGGivePoints()
{
	KotGPoints += 1;
}