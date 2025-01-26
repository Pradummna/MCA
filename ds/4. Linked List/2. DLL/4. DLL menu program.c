#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert at any position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }
    struct Node* temp = *head;
    int currentPos = 1;

    while (temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete from any position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    struct Node* temp = *head;
    int currentPos = 1;

    while (temp != NULL && currentPos < position) {
        temp = temp->next;
        currentPos++;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// Function to display the list forward
void displayForward(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Doubly Linked List is empty!\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    } printf("\n");
}

// Function to display the list backward
void displayBackward(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Doubly Linked List is empty!\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    } printf("\n");
}

// Main function to implement the menu
int main() {
    struct Node* head = NULL;
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
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 4:
                deleteFromBeginning(&head);
                break;

            case 5:
                deleteFromEnd(&head);
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;

            case 7:
                displayForward(head);
                break;

            case 8:
                displayBackward(head);
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
