
#include "RoutePlanner.h"

void RoutePlanner::safeDijkstra(
        int graph[][100],
        bool danger[],
        int cities,
        int source,
        int destination)
{
    int distance[100];
    int parent[100];
    bool visited[100];

    for(int i = 0; i < cities; i++)
    {
        distance[i] = 1000000;
        parent[i] = -1;
        visited[i] = false;
    }

    distance[source] = 0;

    for(int count = 0; count < cities; count++)
    {
        int current = -1;
        int minimum = 1000000;

        for(int i = 0; i < cities; i++)
        {
            if(!visited[i] && distance[i] < minimum)
            {
                minimum = distance[i];
                current = i;
            }
        }

        if(current == -1)
            break;

        visited[current] = true;

        for(int next = 0; next < cities; next++)
        {
            int weight = graph[current][next];

            if(weight > 0 && !danger[next] && !visited[next])
            {
                if(distance[current] + weight < distance[next])
                {
                    distance[next] =
                        distance[current] + weight;

                    parent[next] = current;
                }
            }
        }
    }

    if(distance[destination] == 1000000)
    {
        cout << "\nNo Safe Route Available.\n";
        return;
    }

    cout << "\nSafe Distance = "
         << distance[destination]
         << " km\n";

    int path[100];
    int pathCount = 0;

    int node = destination;

    while(node != -1)
    {
        path[pathCount] = node;
        pathCount++;

        node = parent[node];
    }

    cout << "\nSafe Route : ";

    for(int i = pathCount - 1; i >= 0; i--)
    {
        cout << path[i];

        if(i != 0)
            cout << " -> ";
    }

    cout << endl;
}
