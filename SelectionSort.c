#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[500],i,j,n,temp,k,min,loc;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    printf("Enter the elements of the array : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    //Selection Sort
    for(i = 0; i < n; i++)
    {
        min = a[i];
        loc = i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < min)
            {
                min = a[j];
                loc = j;
            }
        }
        if(i != loc)
        {
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
    }
    
    printf("\nSorted Elements : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
}