#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
    #define INF 99999

void FloydWarshall()
{
    int v = 4;

    int distance[4][4] = {
        {0, 1, 3, 0},
        {0, 0, 1, 6},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    // Initialize distances
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                distance[i][j] = 0;
            else if (distance[i][j] == 0)
                distance[i][j] = INF;
        }
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest distances between vertices:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (distance[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Floyd Warshall Algorithm\n");
    FloydWarshall();
    return 0;
}
