#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*tail == NULL) { // If the list is empty
        newNode->next = newNode;
        newNode->prev = newNode;
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** tail, int value) {
    struct Node* newNode = createNode(value);

    if (*tail == NULL) { // If the list is empty
        newNode->next = newNode;
        newNode->prev = newNode;
        *tail = newNode;
        return;
    }

    newNode->next = (*tail)->next;
    newNode->prev = *tail;
    (*tail)->next->prev = newNode;
    (*tail)->next = newNode;
    *tail = newNode;
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** tail, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) {
        insertAtBeginning(tail, value);
        return;
    }

    struct Node* temp = (*tail)->next;
    int currentPos = 1;

    while (currentPos < position - 1 && temp != *tail) {
        temp = temp->next;
        currentPos++;
    }

    if (currentPos < position - 1) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    if (temp == *tail) {
        *tail = newNode;
    }
}

// Function to delete from the beginning
void deleteFromBeginning(struct Node** tail) {
    if (*tail == NULL) { // If the list is empty
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = (*tail)->next;

    if (*tail == temp) { // If the list has only one node
        free(temp);
        *tail = NULL;
        printf("Node deleted from the beginning.\n");
        return;
    }

    (*tail)->next = temp->next;
    temp->next->prev = *tail;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end
void deleteFromEnd(struct Node** tail) {
    if (*tail == NULL) { // If the list is empty
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = (*tail)->next;

    if (*tail == temp) { // If the list has only one node
        free(temp);
        *tail = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* secondLast = temp;
    while (secondLast->next != *tail) {
        secondLast = secondLast->next;
    }

    secondLast->next = (*tail)->next;
    (*tail)->next->prev = secondLast;
    free(*tail);
    *tail = secondLast;
    printf("Node deleted from the end.\n");
}

// Function to delete from any position
void deleteFromPosition(struct Node** tail, int position) {
    if (*tail == NULL) { // If the list is empty
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(tail);
        return;
    }

    struct Node* temp = (*tail)->next;
    struct Node* prev = NULL;
    int currentPos = 1;

    while (currentPos < position && temp != *tail) {
        prev = temp;
        temp = temp->next;
        currentPos++;
    }

    if (currentPos < position) {
        printf("Position out of bounds!\n");
        return;
    }

    prev->next = temp->next;
    temp->next->prev = prev;

    if (temp == *tail) {
        *tail = prev;
    }

    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// Function to display the circular doubly linked list forward
void displayForward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail->next;
    printf("Circular Doubly Linked List (Forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Function to display the circular doubly linked list backward
void displayBackward(struct Node* tail) {
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = tail;
    printf("Circular Doubly Linked List (Backward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

// Main function to test the circular doubly linked list
int main() {
    struct Node* tail = NULL;
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Any Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&tail, value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&tail, value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&tail, value, position);
                break;

            case 4:
                deleteFromBeginning(&tail);
                break;

            case 5:
                deleteFromEnd(&tail);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&tail, position);
                break;

            case 7:
                displayForward(tail);
                break;

            case 8:
                displayBackward(tail);
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}