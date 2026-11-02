
#ifndef EVACUATIONCENTER_H
#define EVACUATIONCENTER_H

#include <iostream>
#include <string>

using namespace std;

struct Center
{
    string name;
    int cityID;
    int capacity;
    int availableCapacity;
    double safetyScore;
};

class EvacuationCenter
{
private:
    Center centers[100];
    int centerCount;

public:

    EvacuationCenter()
    {
        centerCount = 0;
    }

    void addCenter();

    void displayCenters();

    void recommendCenter(int userCity);
};

#endif
