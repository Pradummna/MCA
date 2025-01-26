// Linked list operation: Insertion from the start
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_beg(struct Node** head, int data) {
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
    insert_at_beg(&head, 10);
    insert_at_beg(&head, 20);
    insert_at_beg(&head, 30);
    
    printf("Linked list after insertion at specific positions: ");
    display(head);
    return 0;
}
