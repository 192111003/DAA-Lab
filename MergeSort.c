#include <stdio.h>
void merge(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;

    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    merge(arr, 0, n - 1);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
