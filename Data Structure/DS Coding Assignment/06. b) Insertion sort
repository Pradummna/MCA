// Array bubble sort program
#include<stdio.h>
#include<stdbool.h>
void printArray(int arr[], int n);
void bubble_sort(int arr[], int n);

int main() {
	int arr[] = {5, 2, 1, 4, 9, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("\nOriginal Array: ");
	printArray(arr, n);	
	bubble_sort(arr, n);

	printf("\nArray after sorting: ");
	printArray(arr, n);
	return 0;
}

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void bubble_sort(int arr[], int n) {
	int temp;
	bool swapped;
	
	for(int i = 0; i < n - 1; i++) {
		swapped = false;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if(swapped == false) {
			break;
		}
	}
    printf("\nBubble sort completed");
}
