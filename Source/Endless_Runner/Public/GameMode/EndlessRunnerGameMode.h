// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessRunnerGameMode.generated.h"

class UUserWidget;
class ABasicFloorTile;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCoinCountChanged, int32, CoinCount);

UCLASS()
class ENDLESS_RUNNER_API AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	class UGameHud* GameHud;
	
	UPROPERTY(EditAnywhere, Category = "Config")
	TSubclassOf<UUserWidget> GameHudClass;

	UPROPERTY(EditAnywhere, Category = "Config")
	TSubclassOf<ABasicFloorTile> FloorTileClass;
	
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	TArray<float> LaneSwitchValues;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	FTransform NextSpawnPoint;

	UPROPERTY(EditAnywhere, Category = "Config")
	int32 NumInitialFloorTiles = 10;

	UPROPERTY(VisibleAnywhere, Category = "Collectables")
	int32 TotalCoins = 0;
	
	UFUNCTION(BlueprintCallable, Category = "Tiles")
	void CreateInitialFloorTiles();
	
public:
	
	UFUNCTION(BlueprintCallable)
	ABasicFloorTile* AddFloorTile(const bool SpawnItems);

	UFUNCTION(BlueprintCallable, Category = "Collectables")
	void AddCoin();
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnCoinCountChanged OnCoinCountChanged;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:

	const TArray<float>& GetLaneValues() const { return LaneSwitchValues; }
};
