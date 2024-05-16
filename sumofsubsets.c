#include <stdio.h>

int sum = 0;
int k = 0;
int m = 10;
int remaining = 30;
int w[3] = {5, 10, 15};
int x[3];
int n = 3;

void sumOfSubset(int sum, int k, int remaining)
{
    if (sum == m)
    {
        for (int i = 0; i < n; i++)
        {
            if (x[i] == 1)
            {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    }
    else if (k < n)
    {
        if (sum + w[k] <= m)
        {
            x[k] = 1;
            sumOfSubset(sum + w[k], k + 1, remaining - w[k]);
        }
        x[k] = 0;
        sumOfSubset(sum, k + 1, remaining);
    }
}

int main()
{
    sumOfSubset(sum, k, remaining);
    return 0;
}
