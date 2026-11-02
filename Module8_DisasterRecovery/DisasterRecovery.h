#ifndef DISASTERRECOVERY_H
#define DISASTERRECOVERY_H

#include <iostream>
#include <string>

using namespace std;

struct RecoveryPlan
{
    string cityName;
    int population;
    double riskScore;
    double recoveryCost;
    int sheltersNeeded;
    int rescueTeamsNeeded;
    int medicalTeamsNeeded;
};

class DisasterRecovery
{
private:
    RecoveryPlan plan;

public:
    void createRecoveryPlan();
    void displayRecoveryPlan();
};

#endif