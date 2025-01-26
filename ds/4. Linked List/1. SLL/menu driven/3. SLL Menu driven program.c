#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void insertAtPosition(struct Node** head, int value, int position);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteFromPosition(struct Node** head, int position);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize an empty list
    int choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    printf("Inserted %d at the beginning.\n", value);
    return newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        printf("Inserted %d as the first element.\n", value);
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
    return head;
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (position == 1) {
        newNode->next = head;
        printf("Inserted %d at position %d.\n", value, position);
        return newNode;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
    return head;
}

// Function to delete from the beginning
void deleteFromBeginning(struct Node** head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
    return head;
}

// Function to delete from the end
void deleteFromEnd(struct Node** head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete from a specific position
void deleteFromPosition(struct Node** head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from position %d.\n", temp->data, position);
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    printf("Deleted %d from position %d.\n", toDelete->data, position);
    free(toDelete);
    return head;
}

// Function to display the list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
