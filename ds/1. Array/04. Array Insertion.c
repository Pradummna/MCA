/* 4.	Write a program to insert an element in an array in the following positions:
	  At the end of the array
	  At any desired location */

#include <stdio.h>
#define MAX 50

void createArray(int *n);
void menu(int arr[], int *n);
void display(int arr[], int n);
void insert_at_the_end(int arr[], int *n);
void insert_at_any_loc(int arr[], int *n);

int main() {
    int n; // Size of the array
    printf("Enter the size to create an array: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX) {
        printf("\n\nInvalid Input. Size should be (1 to %d)", MAX);
        return 1;
    }
    createArray(&n); // Pass the address of n to createArray
    return 0;
}

// Function to create an array
void createArray(int *n) { // Now n is passed by reference
    int arr[MAX], i;
    
    printf("\nInsert elements into array\n");
    for (i = 0; i < *n; i++) {	
        printf("Index %d: ", i);
        scanf("%d", &arr[i]);
    } 						
    printf("\nArray successfully created");
    menu(arr, n); // Pass the array and the address of n
}

// Menu Function
void menu(int arr[], int *n) {
    int choice;
    printf("\n");
    do {
        printf("\nMenu");
        printf("\n 1. Insert element at the end");
        printf("\n 2. Insert element at any desired location");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert_at_the_end(arr, n); // Pass n by reference
                break;
            
            case 2:
                insert_at_any_loc(arr, n); // Pass n by reference
                break;
                
            case 3:
                display(arr, *n); // Display array using the current size
                break;
            
            case 4: 
                printf("\n\nSuccessfully exit");
                break;
                
            default: 
                printf("\n\nInvalid Input");
                break;
        }
    } while (choice != 4);
}

// Display function
void display(int arr[], int n) {
    int i;
    printf("\n\nArray Elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert element at the end of the array
void insert_at_the_end(int arr[], int *n) {
    if (*n >= MAX) {
        printf("\nMemory is full\n");
        return;
    } 
    int elem;
    printf("\n\nEnter the element: ");
    scanf("%d", &elem);
    
    arr[*n] = elem; // Insert the element at the end
    (*n)++; // Increment the size of the array
}

// Function to insert element at any desired location
void insert_at_any_loc(int arr[], int *n) {
    if (*n >= MAX) {
        printf("\nMemory is full\n");
        return;
    }
    int loc, elem, i;
    printf("\nEnter the location (0 to %d): ", *n);
    scanf("%d", &loc);
    
    if (loc < 0 || loc > *n) {
        printf("\n\nWrong Input");
        return;
    }
    printf("\nEnter the element: ");
    scanf("%d", &elem);
    
    // Shift elements to make space at 'loc'
    for (i = *n; i > loc; i--) {
        arr[i] = arr[i - 1];
    }
    arr[loc] = elem; // Insert element at the specified location
    (*n)++; // Increment the size of the array
}