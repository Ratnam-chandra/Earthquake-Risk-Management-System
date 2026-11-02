
#include "Earthquake.h"
#include "../Module2_RiskAssessment/RiskCalculator.h"
#include "../Module3_Statistics/Statistics.h"
#include "../Module4_Prediction/Prediction.h"
#include "../Module5_RoutePlanning/Graph.h"
#include "../Module5_RoutePlanning/RoutePlanner.h"
#include "../Module6_CityClassification/CityRisk.h"
#include "../Module7_EvacuationCenter/EvacuationCenter.h"

#include <map>
#include <iomanip>
#include <stdio.h>

Graph cityGraph;

int totalCities = 0;

bool danger[100] = {false};

EvacuationCenter centerManager;

void EarthquakeManager::addRecord()
{
    if(recordCount >= 1000)
    {
        cout << "\nMaximum Records Reached.\n";
        return;
    }

    Earthquake e;

    cout << "\nEnter Region Name: ";
    cin >> e.region;

    cout << "Enter Magnitude: ";
    cin >> e.magnitude;

    cout << "Enter Depth (km): ";
    cin >> e.depth;

    cout << "Enter Year: ";
    cin >> e.year;

    records[recordCount] = e;
    recordCount++;

    cout << "\nRecord Added Successfully.\n";
}

void EarthquakeManager::displayRecords()
{
    if(recordCount == 0)
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    cout << "\n--------------------------------------------\n";
    cout << "Region\tMagnitude\tDepth\tYear\n";
    cout << "--------------------------------------------\n";

    for(int i = 0; i < recordCount; i++)
    {
        cout << records[i].region << "\t"
             << records[i].magnitude << "\t\t"
             << records[i].depth << "\t"
             << records[i].year << endl;
    }
}

void EarthquakeManager::saveToFile()
{
    FILE *file = fopen("Data/earthquake_data.txt", "w");

    if(file == NULL)
    {
        cout << "\nUnable to Open File.\n";
        return;
    }

    for(int i = 0; i < recordCount; i++)
    {
        fprintf(file, "%s %lf %lf %d\n",
                records[i].region.c_str(),
                records[i].magnitude,
                records[i].depth,
                records[i].year);
    }

    fclose(file);

    cout << "\nData Saved Successfully.\n";
}

void EarthquakeManager::loadFromFile()
{
    FILE *file = fopen("Data/earthquake_data.txt", "r");

    if(file == NULL)
    {
        cout << "\nUnable to Open File.\n";
        return;
    }

    Earthquake e;

    char regionName[100];

    recordCount = 0;

    while(recordCount < 1000 &&
          fscanf(file, "%99s %lf %lf %d",
                 regionName,
                 &e.magnitude,
                 &e.depth,
                 &e.year) == 4)
    {
        e.region = regionName;

        records[recordCount] = e;
        recordCount++;
    }

    fclose(file);

    cout << "\nData Loaded Successfully.\n";
}

Earthquake* EarthquakeManager::getRecords()
{
    return records;
}

int EarthquakeManager::getRecordCount()
{
    return recordCount;
}

void EarthquakeManager::displayRiskReport()
{
    if(recordCount == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    map<string,int> frequency;

    for(int i = 0; i < recordCount; i++)
    {
        frequency[records[i].region]++;
    }

    RiskCalculator riskObj;

    cout << "\n============================================================\n";
    cout << "EARTHQUAKE RISK REPORT\n";
    cout << "============================================================\n";

    cout << left
         << setw(15) << "Region"
         << setw(12) << "Magnitude"
         << setw(12) << "Depth"
         << setw(12) << "Risk"
         << setw(15) << "Category"
         << endl;

    cout << "============================================================\n";

    for(int i = 0; i < recordCount; i++)
    {
        double risk =
            riskObj.calculateRisk(
                records[i].magnitude,
                frequency[records[i].region],
                records[i].depth
            );

        string category =
            riskObj.classifyRisk(risk);

        cout << left
             << setw(15) << records[i].region
             << setw(12) << records[i].magnitude
             << setw(12) << records[i].depth
             << setw(12) << risk
             << setw(15) << category
             << endl;
    }
}

void EarthquakeManager::displayStatistics()
{
    if(recordCount == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    Statistics stat;

    cout << "\n=====================================\n";
    cout << " EARTHQUAKE STATISTICAL REPORT\n";
    cout << "=====================================\n";

    cout << "Total Records      : "
         << recordCount
         << endl;

    cout << "Average Magnitude  : "
         << stat.calculateMean(records, recordCount)
         << endl;

    cout << "Maximum Magnitude  : "
         << stat.calculateMaxMagnitude(records, recordCount)
         << endl;

    cout << "Minimum Magnitude  : "
         << stat.calculateMinMagnitude(records, recordCount)
         << endl;

    cout << "Standard Deviation : "
         << stat.calculateStandardDeviation(records, recordCount)
         << endl;

    stat.displayFrequency(records, recordCount);
}

void EarthquakeManager::displayPredictionReport()
{
    if(recordCount == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    Prediction prediction;

    prediction.generatePredictionReport(records, recordCount);
}

void EarthquakeManager::createRoadNetwork()
{
    cout << "\nEnter Number of Cities : ";
    cin >> totalCities;

    int roads;

    cout << "Enter Number of Roads : ";
    cin >> roads;

    cout << "\nCity IDs start from 0\n";

    for(int i = 1; i <= roads; i++)
    {
        int source;
        int destination;
        int distance;

        cout << "\nRoad "
             << i
             << endl;

        cout << "Source : ";
        cin >> source;

        cout << "Destination : ";
        cin >> destination;

        cout << "Distance : ";
        cin >> distance;

        cityGraph.addRoad(
                source,
                destination,
                distance);
    }

    cout << "\nRoad Network Created Successfully.\n";
}

void EarthquakeManager::findSafeRoute()
{
    int source;
    int destination;

    cout << "\nEnter Source City : ";
    cin >> source;

    cout << "Enter Destination City : ";
    cin >> destination;

    RoutePlanner planner;

    planner.safeDijkstra(
        cityGraph.getGraph(),
        danger,
        totalCities,
        source,
        destination);
}

void EarthquakeManager::markDangerousCity()
{
    int city;

    cout << "\nEnter City ID : ";
    cin >> city;

    cityGraph.markDangerousCity(city);

    danger[city] = true;

    cout << "\nCity "
         << city
         << " marked as Dangerous.\n";
}

void EarthquakeManager::findSafestRoute()
{
    int source;
    int destination;

    cout << "\nEnter Source City : ";
    cin >> source;

    cout << "Enter Destination City : ";
    cin >> destination;

    RoutePlanner planner;

    planner.safeDijkstra(
            cityGraph.getGraph(),
            danger,
            totalCities,
            source,
            destination);
}

void EarthquakeManager::classifyCities()
{
    if(recordCount == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    CityRisk risk;

    risk.classifyCities(records, recordCount);
}

void EarthquakeManager::addEvacuationCenter()
{
    centerManager.addCenter();
}

void EarthquakeManager::displayEvacuationCenters()
{
    centerManager.displayCenters();
}

void EarthquakeManager::recommendEvacuationCenter()
{
    int city;

    cout << "\nEnter Your City ID : ";
    cin >> city;

    centerManager.recommendCenter(city);
}
