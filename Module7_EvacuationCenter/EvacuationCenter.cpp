
#include "EvacuationCenter.h"
#include <cstdlib>

void EvacuationCenter::addCenter()
{
    Center c;

    if(centerCount >= 100)
    {
        cout << "\nMaximum Centers Limit Reached.\n";
        return;
    }

    cout << "\nCenter Name : ";
    cin >> c.name;

    cout << "City ID : ";
    cin >> c.cityID;

    cout << "Capacity : ";
    cin >> c.capacity;

    cout << "Available Capacity : ";
    cin >> c.availableCapacity;

    cout << "Safety Score (1-10): ";
    cin >> c.safetyScore;

    centers[centerCount] = c;
    centerCount++;

    cout << "\nCenter Added Successfully.\n";
}

void EvacuationCenter::displayCenters()
{
    if(centerCount == 0)
    {
        cout << "\nNo Centers Available.\n";
        return;
    }

    cout << "\n===== EVACUATION CENTERS =====\n";

    for(int i = 0; i < centerCount; i++)
    {
        cout << "\nName : "
             << centers[i].name;

        cout << "\nCity : "
             << centers[i].cityID;

        cout << "\nCapacity : "
             << centers[i].capacity;

        cout << "\nAvailable : "
             << centers[i].availableCapacity;

        cout << "\nSafety Score : "
             << centers[i].safetyScore;

        cout << "\n----------------------\n";
    }
}

void EvacuationCenter::recommendCenter(int userCity)
{
    if(centerCount == 0)
    {
        cout << "\nNo Centers Available.\n";
        return;
    }

    double bestScore = -100000;
    Center bestCenter;

    for(int i = 0; i < centerCount; i++)
    {
        int distance =
            abs(userCity - centers[i].cityID);

        double score =
            (centers[i].safetyScore * 10)
            - distance
            + (centers[i].availableCapacity / 10.0);

        if(score > bestScore)
        {
            bestScore = score;
            bestCenter = centers[i];
        }
    }

    cout << "\n========================";
    cout << "\n BEST EVACUATION CENTER";
    cout << "\n========================";

    cout << "\nName : "
         << bestCenter.name;

    cout << "\nCity ID : "
         << bestCenter.cityID;

    cout << "\nSafety Score : "
         << bestCenter.safetyScore;

    cout << "\nAvailable Capacity : "
         << bestCenter.availableCapacity;

    cout << "\nRecommendation Score : "
         << bestScore;

    cout << endl;
}
