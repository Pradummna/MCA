#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at any position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) { // Insert at the beginning
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    int currentPos = 1;
    // Traverse to the position before where we want to insert
    while (temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) { // If position is out of bounds
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }
    // Insert the new node
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the list forward
void displayForward(struct Node* head) {
    struct Node* temp = head;

    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    } printf("\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    struct Node* temp = head;

    // Traverse to the last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    } printf("\n");
}

// Main function to test the insertion
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    // Insert nodes at specific positions
    insertAtPosition(&head, 10, 1); // Insert 10 at position 1
    insertAtPosition(&head, 20, 2); // Insert 20 at position 2
    insertAtPosition(&head, 30, 2); // Insert 30 at position 2
    insertAtPosition(&head, 40, 5); // Out of bounds test

    // Display the list forward and backward
    displayForward(head);
    displayBackward(head);
    return 0;
}