#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int lb, int ub);
void merge(int a[], int lb, int mid, int ub);

void main()
{
    int a[100], i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("\nSorted Elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void mergesort(int a[], int lb, int ub)
{
    int mid = (lb + ub) / 2;
    if (lb < ub)
    {

        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

void merge(int a[], int lb, int mid, int ub)
{
    int b[100];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    if (j > ub)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    else
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}