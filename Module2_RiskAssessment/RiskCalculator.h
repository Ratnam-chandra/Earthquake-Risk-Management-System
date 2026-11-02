#ifndef RISKCALCULATOR_H
#define RISKCALCULATOR_H

#include <iostream>
#include <string>

using namespace std;

class RiskCalculator
{
public:

    double calculateRisk(double magnitude,
                         int frequency,
                         double depth);

    string classifyRisk(double risk);
};

#endif