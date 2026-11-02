
#ifndef PREDICTION_H
#define PREDICTION_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Earthquake;

class Prediction
{
public:

    double calculateAverageMagnitude(Earthquake records[],
                                     int recordCount,
                                     string region);

    int calculateFrequency(Earthquake records[],
                          int recordCount,
                          string region);

    double predictRisk(Earthquake records[],
                       int recordCount,
                       string region);

    void generatePredictionReport(Earthquake records[],
                                  int recordCount);
};

#endif
