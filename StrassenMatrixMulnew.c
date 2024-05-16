#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    clock_t t;
    int a[2][2], b[2][2], c[2][2], i, j;
    int s1,s2,s3,s4,s5,s6,s7;
    
    printf("Enter elements for matrix 1 : ");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    printf("Enter elements for matrix 2 : ");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    
    printf("\nMatrix 1 : ");
    for(i = 0; i < 2; i++)
    {
        printf("\n");
        for(j = 0; j < 2; j++)
        {
            printf("%d\t",a[i][j]);
        }
    }
    
    printf("\nMatrix 2 : ");
    for(i = 0; i < 2; i++)
    {
        printf("\n");
        for(j = 0; j < 2; j++)
        {
            printf("%d\t",b[i][j]);
        }
    }
    
    t = clock();
    s1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    s2 = b[0][0] * (a[1][0] + a[1][1]);
    s3 = a[0][0] * (b[0][1] - b[1][1]);
    s4 = a[1][1] * (b[1][0] - b[0][0]);
    s5 = b[1][1] * (a[0][0] + a[0][1]);
    s6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    s7 = (b[1][0] + b[1][1]) * (a[0][1] - a[1][1]);
    
    c[0][0] = s1 + s4 - s5 + s7;
    c[0][1] = s3 + s5;
    c[1][0] = s2 + s4;
    c[1][1] = s1 + s3 - s2 + s6;
    
   
    printf("\n\nAfter Strassen's Algorithm");
    for(i = 0; i < 2; i++)
    {
        printf("\n");
        for(j = 0; j < 2; j++)
        {
            printf("%d\t",c[i][j]);
        }
    }
    t = clock() - t;
    printf("\n\nTime taken : %f",((float)t) / CLOCKS_PER_SEC);
}