// Insert and Delete node from the end
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\nItem successfully inserted into the node.");
}

void deleteFromEnd(struct Node** head) {
    if(*head == NULL) {
        printf("\nUnderflow. There is nothing to delete.");
        return;
    }
    struct Node* temp = *head;
    if((*head)->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
    printf("\nItem successfully deleted from the node.");
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
        printf("1. Insert Node at the End\n");
        printf("2. Delete Node from the End\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int data;
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
            }
            break;

            case 2:
                deleteFromEnd(&head);
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
