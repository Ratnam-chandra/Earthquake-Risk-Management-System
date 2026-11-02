
#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include <iostream>

using namespace std;

class RoutePlanner
{
public:

    void safeDijkstra(
        int graph[][100],
        bool danger[],
        int cities,
        int source,
        int destination
    );
};

#endif
