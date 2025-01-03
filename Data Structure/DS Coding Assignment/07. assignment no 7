// 7. Write an interactive program to create an array of 20 records having following field: name and marks. Sort the record (based on marks) using bubble sort. Search for a record using binary search. 
#include <stdio.h>
#include <string.h>
#define SIZE 20

// Define structure for student record
typedef struct {
    char name[50];
    int marks;
} Student;

// Function to sort records using Bubble Sort
void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks > arr[j + 1].marks) {
                // Swap the records
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search
int binarySearch(Student arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].marks == key) {
            return mid; // Found the record
        } else if (arr[mid].marks < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Record not found
}

int main() {
    Student students[SIZE];
    int searchMarks, index;

    // Input student records
    printf("Enter details for %d students:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Student %d\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name); // Read string with spaces
        printf("Enter marks: ");
        scanf("%d", &students[i].marks);
    }

    // Sort the records
    bubbleSort(students, SIZE);

    // Display sorted records
    printf("\nSorted Records (by marks):\n");
    printf("Name\tMarks\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%s\t%d\n", students[i].name, students[i].marks);
    }

    // Search for a record
    printf("\nEnter the marks to search: ");
    scanf("%d", &searchMarks);
    index = binarySearch(students, SIZE, searchMarks);

    if (index != -1) {
        printf("\nRecord found:\n");
        printf("Name: %s, Marks: %d\n", students[index].name, students[index].marks);
    } else {
        printf("\nRecord with marks %d not found.\n", searchMarks);
    }
    return 0;
}
