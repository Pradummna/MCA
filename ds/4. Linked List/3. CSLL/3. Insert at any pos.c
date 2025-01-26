#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the list (used in insertAtPosition)
void insertAt(struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*tail == NULL) { // If the list is empty
        newNode->next = newNode;  // Points to itself
        *tail = newNode;
    } else {
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
    }
}

// Function to insert at a specific position
void insertAtPosition(struct Node** tail, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) { // Insert at the beginning
        insertAt(tail, value);
        return;
    }

    struct Node* temp = (*tail)->next;
    int currentPos = 1;

    // Traverse to the position before the desired position
    while (currentPos < position - 1 && temp != *tail) {
        temp = temp->next;
        currentPos++;
    }

    // If position is out of bounds
    if (temp == *tail && currentPos < position - 1) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;

    // If inserted at the end, update the tail
    if (temp == *tail) {
        *tail = newNode;
    }
}

// Function to display the circular singly linked list
void display(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail->next;
    printf("Circular Singly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Main function to test the circular singly linked list
int main() {
    struct Node* tail = NULL; // Initialize the tail of the list
    // Insert nodes at the end
    insertAtPosition(&tail, 10, 1);
    insertAtPosition(&tail, 20, 2);
    insertAtPosition(&tail, 30, 2);

    // Display the list
    display(tail);
    return 0;
}
