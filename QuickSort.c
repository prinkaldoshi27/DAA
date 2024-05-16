#include<stdio.h>
#include<stdlib.h>

void quicksort(int a[], int lb, int ub);
int partition(int a[], int lb, int ub);

void main()
{
    int a[100],i,n;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    quicksort(a, 0, n - 1);
    
    printf("\nSorted Elements:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void quicksort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = partition(a, lb, ub);
        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
    }
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) 
    {
        while (a[start] <= pivot) 
        {
            start++;
        }
        while (a[end] > pivot) 
        {
            end--;
        }
        if (start < end) 
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    int temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}
