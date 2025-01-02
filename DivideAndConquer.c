#include <stdio.h>
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = arr[low];
        return;
    }
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }
    
    int mid = (low + high) / 2;
    
    int leftMax, leftMin, rightMax, rightMin;
  
    findMaxMin(arr, low, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);
    
    *max = (leftMax > rightMax) ? leftMax : rightMax;
    *min = (leftMin < rightMin) ? leftMin : rightMin;
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max, min;
    findMaxMin(arr, 0, n - 1, &max, &min);   
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    
    return 0;
}
