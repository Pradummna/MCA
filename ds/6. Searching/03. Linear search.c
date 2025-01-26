// 3.	Write a program to implement linear search.
#include<stdio.h>

int linearSearch(int arr[], int n, int value);

int main() {
  int arr[] = {11, 20, 34, 46, 57};
  int i, value;

  printf("Program to implement linear search");
  printf("\nEnter the value: ");
  scanf("%d",&value);

  int found = linearSearch(arr, 5, value);

  if(found == -1) {
    printf("\n%d value is not found in array: ", value);
  } else {
    printf("\n%d value is found in array index: %d ", value, found);
  }
  return 0;
}

// Function to perform linear search
int linearSearch(int arr[], int n, int value) {
  int i;
  for(i=0; i<n; i++) {
    if(arr[i] == value) {
      return i;
    }
  } 
  return -1;
}
