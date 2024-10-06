// 2.	Write a program to traverse a 1-d array and add number 5 to each element of the array.
#include<stdio.h>

void createArray(int arr[], int n);
void printArray(int arr[], int n);
void traverseAndAdd(int arr[], int n);

int main() {
  int arr[5];
  printf("Program to traverse a 1-d array and add number 5 to each element of the array.");

  createArray(arr, 5);
  printf("\n\nPrinting array elements: ");
  printArray(arr, 5);
  
  printf("\n\nTraversing in array and add 5 in every element\n");
  traverseAndAdd(arr, 5);
  
  printf("\n\nPrinting new array elements after traversing: ");
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
  printf("\nElements successfully added");
}

// Function to display the elements from an array
void printArray(int arr[], int n) {
  int i;
  for(i=0; i<n; i++) {
    printf("%d ",arr[i]);
  }
}

// Function to traverse and add 5 in each of the elements
void traverseAndAdd(int arr[], int n) {
  int i;
  for(i=0; i<n; i++) {
      arr[i] += 5; 
  }
  printf("\nTraversing successfully completed");
}
