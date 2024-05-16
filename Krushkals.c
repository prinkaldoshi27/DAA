#include <stdio.h>
#define MAX_VERTICES 5
#define MAX 999
int cost[MAX_VERTICES][MAX_VERTICES];
int parent[MAX_VERTICES] = {0};
int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main()
{
    int n = MAX_VERTICES, ne = 1, mincost = 0;
    printf("\n\tImplementation of Kruskal's algorithm\n");
    printf("\nEnter the cost adjacency matrix:\n");
    int cost[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 7, 0, 0},
        {1, 0, 5, 4, 3},
        {7, 5, 0, 0, 6},
        {0, 4, 0, 0, 2},
        {0, 3, 6, 2, 0}};
    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        int min = MAX;
        int a = -1, b = -1;
        int u = -1, v = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min && cost[i][j] > 0) // Ensure we don't pick zero-cost self-loops
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        if (a != -1 && b != -1) // Ensure we have found a valid
            edge
            {
                u = find(u);
                v = find(v);
                if (uni(u, v))
                {
                    printf("%d edge (%d,%d) = %d\n", ne++, a + 1, b + 1,
                           min); // a+1 and b+1 for 1-based indexing in output
                    mincost += min;
                }
                cost[a][b] = cost[b][a] = MAX;
            }
    }
    printf("\n\tMinimum cost = %d\n", mincost);
    return 0;
}