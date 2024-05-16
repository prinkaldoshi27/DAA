#include<stdio.h>
#include<stdlib.h>

void main()
{
    int a[500],i,j,n,temp,k;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    
    printf("Enter the elements of the array : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    
    //Insertion Sort
    for(k = 0; k < n; k++)
    {
        temp = a[k];
        j = k - 1;
        while(j >= 0 && temp < a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    
    printf("\nSorted Elements : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    
}