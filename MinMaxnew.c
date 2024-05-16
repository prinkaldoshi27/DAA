
#include <stdio.h>

// Function to find maximum and minimum using Divide and Conquer approach
void DAC_MAXMIN(int A[], int low, int high, int *min, int *max) {
    int mid, LMin, LMax, RMin, RMax;

    if (low == high) { // Base case: If only one element
        *min = A[low];
        *max = A[low];
    } else if (high == low + 1) { // Base case: If only two elements
        if (A[low] < A[high]) {
            *min = A[low];
            *max = A[high];
        } else {
            *min = A[high];
            *max = A[low];
        }
    } else {
        mid = (low + high) / 2;
        DAC_MAXMIN(A, low, mid, &LMin, &LMax);
        DAC_MAXMIN(A, mid + 1, high, &RMin, &RMax);

        if (LMax > RMax)
            *max = LMax;
        else
            *max = RMax;

        if (LMin < RMin)
            *min = LMin;
        else
            *min = RMin;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    int min, max;
    DAC_MAXMIN(A, 0, n - 1, &min, &max);

    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);

    return 0;
}
