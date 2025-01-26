// Linked list operation: Insertion from the end
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_the_end(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    } printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    insert_at_the_end(&head, 5);
    insert_at_the_end(&head, 15);
    insert_at_the_end(&head, 25);
    printf("Linked list after insertion at the end: ");
    display(head);
    return 0;
}
