#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate the middle index
        // Check if target is at the middle
        if (arr[mid] == target) {
            return mid;  // Target found
        }
        // If target is greater, ignore the left half
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }
    return -1;  // Target not found
}

// Function to print the result
void printResult(int result) {
    if (result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", result);
    }
}

int main() {
    int arr[] = {11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("\nEnter element: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);
    printResult(result);
    return 0;
}
