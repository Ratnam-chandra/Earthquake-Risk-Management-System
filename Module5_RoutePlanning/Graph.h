
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

class Graph
{
private:

    int adj[100][100];

    bool dangerous[100];

public:

    Graph();

    void addRoad(int source,
                 int destination,
                 int distance);

    void markDangerousCity(int city);

    bool isDangerous(int city);

    int (*getGraph())[100];
};

#endif
