// Insertion sort
#include<stdio.h>

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void insertion_sort(int arr[], int n) {
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp <= arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    } printf("\nInsertion sorting completed");
}

int main() {
    int arr[] = {4, 7, 2, 6, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    display(arr, n);
    insertion_sort(arr, n);
    printf("\nArray after sorting: ");
    display(arr, n);
    return 0;
}
