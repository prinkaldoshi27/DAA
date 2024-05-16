#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[500],i,j,n,temp,low,mid,high,f,s;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    printf("Enter the elements of the array : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    //Sorting the array elements
    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    printf("\nEnter the element to be searched : ");
    scanf("%d",&s);
    
    //Binary Search Technique
    low = 0; 
    high = n-1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(s == a[mid])
        {
            f = 1;
            break;
        }
        else if(s > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    if(f == 1)
    {
        printf("\nElement found.");
    }
    else
    {
        printf("\nElement not found.");
    }
}