#include<stdio.h>
#define n 6

void sort(int start[], int end[]){
    int temp;
    for(int i=0;i<n;i++){
        for(int j =i+1 ; j<n; j++){
            if(end[i]>end[j]){
                temp = end[i];
                end[i] = end[j];
                end[j] = temp;
                
                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

void activity(int start[], int end[]){
    int selected = 0, count =0;
    for(int i=0;i<n;i++){
        if(selected <= start[i]){
            printf("\n%d -> %d",start[i],end[i]);
            selected=end[i];
            count++;
        }
    }
    printf("\nTotal Activities : %d",count);
}

int main(){
    int start[6] = {5,1,3,0,5,8};
    int end[6] = {9,2,4,6,7,9};
    sort(start, end);
    activity(start, end);
    return 0;
}   