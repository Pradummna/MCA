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

void insertAtBeg(struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*tail == NULL) { // If the list is empty
        newNode->next = newNode;
        *tail = newNode;
        return;
    }
    // Insert the new node at the beginning
    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
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
    insertAtBeg(&tail, 10);
    insertAtBeg(&tail, 20);
    insertAtBeg(&tail, 30);

    // Display the list
    display(tail);
    return 0;
}