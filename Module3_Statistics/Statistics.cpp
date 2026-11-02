
#include "Statistics.h"
#include "../Module1_DataManagement/Earthquake.h"

double Statistics::calculateMean(Earthquake records[], int recordCount)
{
    if(recordCount == 0)
        return 0;

    double sum = 0;

    for(int i = 0; i < recordCount; i++)
    {
        sum += records[i].magnitude;
    }

    return sum / recordCount;
}

double Statistics::calculateMaxMagnitude(Earthquake records[], int recordCount)
{
    if(recordCount == 0)
        return 0;

    double mx = records[0].magnitude;

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].magnitude > mx)
            mx = records[i].magnitude;
    }

    return mx;
}

double Statistics::calculateMinMagnitude(Earthquake records[], int recordCount)
{
    if(recordCount == 0)
        return 0;

    double mn = records[0].magnitude;

    for(int i = 0; i < recordCount; i++)
    {
        if(records[i].magnitude < mn)
            mn = records[i].magnitude;
    }

    return mn;
}

double Statistics::calculateStandardDeviation(Earthquake records[], int recordCount)
{
    if(recordCount == 0)
        return 0;

    double mean = calculateMean(records, recordCount);

    double sum = 0;

    for(int i = 0; i < recordCount; i++)
    {
        sum += pow(records[i].magnitude - mean, 2);
    }

    return sqrt(sum / recordCount);
}

void Statistics::displayFrequency(Earthquake records[], int recordCount)
{
    map<string,int> freq;

    for(int i = 0; i < recordCount; i++)
    {
        freq[records[i].region]++;
    }

    cout << "\n===== REGION FREQUENCY =====\n";

    for(map<string,int>::iterator x = freq.begin();
        x != freq.end(); x++)
    {
        cout << x->first
             << " : "
             << x->second
             << endl;
    }
}
