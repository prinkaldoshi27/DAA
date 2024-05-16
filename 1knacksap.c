#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knacksap(int m, int weight[], int profit[], int n)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (weight[n - 1] > m)
    {
        return knacksap(m, weight, profit, n - 1);
    }

    else
    {
        return max(
            profit[n - 1] + knacksap(m - weight[n - 1], weight, profit, n - 1),
            knacksap(m, weight, profit, n - 1));
    }
}

int main()
{
    int profit[4] = {1, 2, 5, 6};
    int weight[4] = {2, 3, 4, 5};
    int n = 4;
    int m = 8;
    printf("%d", knacksap(m, weight, profit, n));
    return 0;
}