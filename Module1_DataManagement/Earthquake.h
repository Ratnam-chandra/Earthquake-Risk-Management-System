
#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

#include <iostream>
#include <stdio.h>

using namespace std;

struct Earthquake
{
    string region;
    double magnitude;
    double depth;
    int year;
};

class EarthquakeManager
{
private:
    Earthquake records[1000];
    int recordCount;

public:
    EarthquakeManager()
    {
        recordCount = 0;
    }

    void addRecord();
    void displayRecords();
    void saveToFile();
    void loadFromFile();

    void displayRiskReport();

    void displayStatistics();

    void displayPredictionReport();

    void createRoadNetwork();
    void findSafeRoute();

    void markDangerousCity();
    void findSafestRoute();

    void classifyCities();

    void addEvacuationCenter();
    void displayEvacuationCenters();
    void recommendEvacuationCenter();

    Earthquake* getRecords();
    int getRecordCount();
};

#endif
