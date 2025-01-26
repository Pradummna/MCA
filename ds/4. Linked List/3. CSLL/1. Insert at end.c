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

// Function to insert a node at the end of a circular singly linked list
void insertAtEnd(struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*tail == NULL) { // If the list is empty
        newNode->next = newNode; // Point to itself
        *tail = newNode;
        return;
    }
    // Insert new node at the end and adjust pointers
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    *tail = newNode;
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
    insertAtEnd(&tail, 10);
    insertAtEnd(&tail, 20);
    insertAtEnd(&tail, 30);

    // Display the list
    display(tail);
    return 0;
}