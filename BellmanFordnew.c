#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define OG 999

int d[MAX];
int parent[MAX];
int w[4][4] = {
    {0, 1, 3, 0},
    {0, 0, 1, 6},
    {0, 0, 0, 1},
    {0, 0, 0, 0}};

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = OG;
        parent[i] = -1;
    }
    d[0] = 0;
}

void relax(int u, int v)
{
    if (d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        parent[v] = u;
    }
}

void bellmanFord(int n)
{
    for (int j = 0; j < n - 1; j++) // n-1 times relaxation procss will RUN
    {
        for (int u = 0; u < n; u++) // for each edge
        {
            for (int v = 0; v < n; v++) // for each vertex
            {
                if (w[u][v] != 0)
                {
                    relax(u, v);
                }
            }
        }
    }
}

int main()
{
    int n = 4;

    initialize(n);
    bellmanFord(n);

    printf("Shortest distances from source node:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d, Parent: %d\n", i, d[i], parent[i] + 1);
    }

    return 0;
}