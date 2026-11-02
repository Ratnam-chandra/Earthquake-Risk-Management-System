
#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct Earthquake;

class Statistics
{
public:

    double calculateMean(Earthquake records[], int recordCount);

    double calculateMaxMagnitude(Earthquake records[], int recordCount);

    double calculateMinMagnitude(Earthquake records[], int recordCount);

    double calculateStandardDeviation(Earthquake records[], int recordCount);

    void displayFrequency(Earthquake records[], int recordCount);
};

#endif
