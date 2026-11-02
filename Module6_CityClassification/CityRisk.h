
#ifndef CITYRISK_H
#define CITYRISK_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Earthquake;

class CityRisk
{
public:

    double calculateRiskScore(
            Earthquake records[],
            int recordCount,
            string region);

    void classifyCities(
            Earthquake records[],
            int recordCount);
};

#endif
