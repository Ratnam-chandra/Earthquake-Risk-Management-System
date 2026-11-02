
#include "Graph.h"

Graph::Graph()
{
    for(int i = 0; i < 100; i++)
    {
        dangerous[i] = false;

        for(int j = 0; j < 100; j++)
        {
            adj[i][j] = 0;
        }
    }
}

void Graph::addRoad(int source,
                    int destination,
                    int distance)
{
    adj[source][destination] = distance;

    adj[destination][source] = distance;
}

void Graph::markDangerousCity(int city)
{
    dangerous[city] = true;
}

bool Graph::isDangerous(int city)
{
    return dangerous[city];
}

int (*Graph::getGraph())[100]
{
    return adj;
}
