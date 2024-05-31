// Adjusted header file for exporting data to CSV

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_LoggertoCSV.generated.h"

UCLASS()
class DSHIFTERS_API ABP_LoggertoCSV : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABP_LoggertoCSV();

    // Function to append a row to the CSV file
    UFUNCTION(BlueprintCallable, Category = "CSV Export")
    void AppendRowToCSV(int32 Turns, int32 Attacks, int32 Movement, bool bWon, int32 EnemyHealth, int32 PlayerHealth, float Rewards);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
