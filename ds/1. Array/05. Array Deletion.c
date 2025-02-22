/* 5.Write a program to delete an element from an array from the following positions:
		From the end of the array
		From any desired location*/

#include<stdio.h>
#define MAX 50

void createArray(int *n);
void display(int arr[], int n);
void menu(int arr[], int *n);
void delete_at_the_end(int *n);
void delete_at_any_loc(int arr[], int *n);

int main() {
	int n;
	printf("Enter the size: ");
	scanf("%d",&n);
	
	if(n < 0 || n >= MAX) {
		printf("\n\nInvalid Input. Size should be (1 to %d)", MAX);
    return 1; 
	}
	createArray(&n);
	return 0;
}

// Function to create an array
void createArray(int *n) { 
    int arr[MAX], i;
    
    printf("\nInsert elements into array\n");
    for (i = 0; i < *n; i++) {	
        printf("Index %d: ", i);
        scanf("%d", &arr[i]);
    } 						
    printf("\nArray successfully created");
    menu(arr, n);
}

// Menu Function
void menu(int arr[], int *n) {
    int choice;
    printf("\n");
    do {
        printf("\nMenu");
        printf("\n 1. Delete element at the end");
        printf("\n 2. Delete element at any desired location");
        printf("\n 3. Display");
        printf("\n 4. Exit");
        
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                delete_at_the_end(arr, n);
                break;
            
            case 2:
                delete_at_any_loc(arr, n); 
                break;
                
            case 3:
                display(arr, *n);
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
    } printf("\n");
}

void delete_at_the_end(int *n) {
	if(*n > 0) {
		(*n)--;
		printf("\nElement deleted successfully\n");
	} else {
		printf("\nMemory is empty\n");
	}
}

void delete_at_any_loc(int arr[], int *n) {
	int i, loc;

	if(*n > 0) {
		printf("\nEnter the location (0 to %d): ", *n - 1);
		scanf("%d", &loc);

		if(loc < 0 || loc >= *n) {
			printf("\nInvalid location\n");
			return;
		}

		for(i = loc; i < *n - 1; i++) {
			arr[i] = arr[i + 1];
		} (*n)--;
		printf("\nElement deleted successfully\n");
	} else {
		printf("\nMemory is empty\n");
	}
}
