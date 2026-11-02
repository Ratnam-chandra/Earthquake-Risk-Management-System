
#include "CityRisk.h"
#include "../Module1_DataManagement/Earthquake.h"

double CityRisk::calculateRiskScore(
        Earthquake records[],
        int recordCount,
        string region)
{
    double magnitudeSum = 0;
    int frequency = 0;

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].region == region)
        {
            magnitudeSum += records[i].magnitude;
            frequency++;
        }
    }

    if(frequency == 0)
        return 0;

    double averageMagnitude =
            magnitudeSum / frequency;

    return averageMagnitude * frequency;
}

void CityRisk::classifyCities(
        Earthquake records[],
        int recordCount)
{
    map<string,bool> visited;

    cout << "\n================================";
    cout << "\n AUTOMATIC CITY CLASSIFICATION";
    cout << "\n================================\n";

    for(int i = 0; i < recordCount; i++)
    {
        if(visited[records[i].region])
            continue;

        visited[records[i].region] = true;

        double score =
            calculateRiskScore(
                records,
                recordCount,
                records[i].region);

        cout << "\nRegion : "
             << records[i].region;

        cout << "\nRisk Score : "
             << score;

        if(score < 10)
        {
            cout << "\nStatus : SAFE\n";
        }
        else if(score < 20)
        {
            cout << "\nStatus : MODERATE RISK\n";
        }
        else
        {
            cout << "\nStatus : HIGH RISK\n";
        }

        cout << endl;
    }
}
