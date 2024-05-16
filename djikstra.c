#include <stdio.h>
#define n 5
#include <limits.h>

int min(int d[], int visited[])
{
    int min = INT_MAX;
    int minEle;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && d[i] < min)
        {
            min = d[i];
            minEle = i;
        }
    }
    return minEle;
}

void djikstra(int w[5][5])
{
    int visited[5];
    int parent[5];
    int d[5];
    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        visited[i] = 0;
    }
    parent[0] = -1;
    d[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int minEle = min(d, visited);
        visited[minEle] = 1;
        for (int j = 0; j < n; j++)
        {
            if (w[minEle][j] != 0 && visited[j] == 0 && d[j] > d[minEle] + w[minEle][j])
            {
                d[j] = d[minEle] + w[minEle][j];
                parent[j] = minEle;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        printf("Parent(%d) - Vertex(%d) \t%d \n", (parent[i] + 1), i + 1, d[i]);
    }
}

int main()
{
    int w[5][5] = {{0, 6, 1, 3, 0},
                   {6, 0, 2, 0, 4},
                   {1, 2, 0, 0, 6},
                   {3, 0, 0, 0, 5},
                   {0, 4, 6, 5, 0}};
    djikstra(w);
    return 0;
}