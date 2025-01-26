#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Insert the new node at the end
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

// Main function to test the doubly linked list
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    // Insert nodes into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the list forward and backward
    displayForward(head);
    displayBackward(head);

    return 0;
}
