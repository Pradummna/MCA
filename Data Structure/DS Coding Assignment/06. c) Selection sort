// Selection sort
#include<stdio.h>

void display(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void selection_sort(int arr[], int n) {
    int min_idx, temp;
    for(int i = 0; i < n - 1; i++) {
        min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    display(arr, n);
    selection_sort(arr, n);

    printf("\nArray after sorting: ");
    display(arr, n);
    return 0;
}
