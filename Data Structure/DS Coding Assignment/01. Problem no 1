// 1. Write a program to input 5 integer values and print them on the screen.
// Solution: 
#include<stdio.h>

void createArray(int arr[], int n);
void printArray(int arr[], int n);

int main() {
  int arr[5];
  printf("program to input 5 integer values and print them on the screen.");
  createArray(arr, 5);
  printArray(arr, 5);
  return 0;
}

// Function to create array
void createArray(int arr[], int n) {
  int i;
  printf("\nInsert elements into an array:\n");
  for (i = 0; i < n; i++) {
    printf("Index %d: ", i);
    scanf("%d", &arr[i]);
  }
  printf("\nElements successfully added\n");
}

// Function to display the elements from array
void printArray(int arr[], int n) {
  int i;
  printf("\nPrinting array elements:\n");
  for(i=0; i<n; i++) {
    printf("%d ",arr[i]);
  }
}
