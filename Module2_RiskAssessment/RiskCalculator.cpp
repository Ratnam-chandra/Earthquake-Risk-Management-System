#include "RiskCalculator.h"

double RiskCalculator::calculateRisk(double magnitude,
                                     int frequency,
                                     double depth)
{
    return (magnitude * 10)
           + (frequency * 5)
           + (100.0 / depth);
}

string RiskCalculator::classifyRisk(double risk)
{
    if(risk < 50)
        return "Low";

    else if(risk < 100)
        return "Medium";

    else if(risk < 150)
        return "High";

    else
        return "Very High";
}