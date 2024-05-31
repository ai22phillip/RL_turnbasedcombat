#include "BP_LoggertoCSV.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

// Sets default values
ABP_LoggertoCSV::ABP_LoggertoCSV()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABP_LoggertoCSV::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABP_LoggertoCSV::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function to append a row to the CSV file with specified data
void ABP_LoggertoCSV::AppendRowToCSV(int32 Turns, int32 Attacks, int32 Movement, bool bWon, int32 EnemyHealth, int32 PlayerHealth, float Rewards)
{
    // Format the row data string with columns and values
    FString RowData = FString::Printf(TEXT("%d,%d,%d,%d,%d,%d,%f"), Turns, Attacks, Movement, bWon ? 1 : 0, EnemyHealth, PlayerHealth, Rewards);

    FString FilePath = FPaths::ProjectSavedDir() + "MyData.csv";

    // Check if the CSV file exists
    if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
    {
        // Create the CSV file with header row
        FString HeaderRow = "Turns,Attacks,Movement,Won,EnemyHealth,PlayerHealth,Rewards\n";
        FFileHelper::SaveStringToFile(HeaderRow, *FilePath);
    }

    // Open the CSV file for appending
    FString CSVData;
    if (FFileHelper::LoadFileToString(CSVData, *FilePath))
    {
        CSVData += RowData + "\n"; // Add the new row data
        FFileHelper::SaveStringToFile(CSVData, *FilePath);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to open CSV file for appending"));
    }
}


