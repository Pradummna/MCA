// Insert and Delete Node at the beginning
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBegg(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    } printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice;

    do {
        printf("Menu\n");
        printf("1. Insert Node at the beginning\n");
        printf("2. Delete Node from the beginning\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int data;
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtBegg(&head, data);
            }
            break;

            case 2:
                deletionAtBegg(&head);
                break;

            case 3:
                display(head);
                break;
            
            case 4:
                printf("\nExit from Program Menu");
                break;
            
            default: 
                printf("\nWrong Input");
                break;
        }
    } while(choice != 4);
    return 0;
}
