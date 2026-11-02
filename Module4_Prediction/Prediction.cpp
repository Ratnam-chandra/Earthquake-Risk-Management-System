
#include "Prediction.h"
#include "../Module1_DataManagement/Earthquake.h"

double Prediction::calculateAverageMagnitude(
            Earthquake records[],
            int recordCount,
            string region)
{
    double sum = 0;
    int count = 0;

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].region == region)
        {
            sum += records[i].magnitude;
            count++;
        }
    }

    if(count == 0)
        return 0;

    return sum / count;
}

int Prediction::calculateFrequency(
            Earthquake records[],
            int recordCount,
            string region)
{
    int count = 0;

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].region == region)
            count++;
    }

    return count;
}

double Prediction::predictRisk(
            Earthquake records[],
            int recordCount,
            string region)
{
    double avgMagnitude =
            calculateAverageMagnitude(records,
                                      recordCount,
                                      region);

    int frequency =
            calculateFrequency(records,
                               recordCount,
                               region);

    double predictedRisk =
            avgMagnitude * frequency;

    return predictedRisk;
}

void Prediction::generatePredictionReport(
            Earthquake records[],
            int recordCount)
{
    map<string,bool> visited;

    cout << "\n========================================";
    cout << "\n FUTURE EARTHQUAKE RISK PREDICTION";
    cout << "\n========================================\n";

    for(int i = 0; i < recordCount; i++)
    {
        if(visited[records[i].region])
            continue;

        visited[records[i].region] = true;

        double risk =
                predictRisk(records,
                            recordCount,
                            records[i].region);

        cout << "\nRegion : "
             << records[i].region;

        cout << "\nPredicted Risk Index : "
             << risk;

        if(risk < 10)
            cout << "\nFuture Risk : LOW";

        else if(risk < 20)
            cout << "\nFuture Risk : MEDIUM";

        else
            cout << "\nFuture Risk : HIGH";

        cout << "\n";
    }
}
