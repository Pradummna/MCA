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

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) { // If the list is empty
        *head = newNode;
        return;
    }
    // Update the head's previous pointer and new node's next pointer
    newNode->next = *head;
    (*head)->prev = newNode;
    // Make the new node the new head
    *head = newNode;
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

    // Insert nodes at the beginning
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    // Display the list
    displayForward(head);
    displayBackward(head);
    return 0;
}