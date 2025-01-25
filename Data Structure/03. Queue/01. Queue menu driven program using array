// Queue menu driven program using array. Operations: Enqueue, Dequeue, Peek,
#include<stdio.h>
#define size 50

void display(int queue[], int front, int rear);
void enqueue(int queue[], int *front, int *rear);
void dequeue(int queue[], int *front, int *rear);
void peek(int queue[], int front, int rear);
int isEmpty(int front, int rear);
int isFull(int rear);

int main() {
    int front = -1, rear = -1;
    int queue[size];
    int choice;

    do {
        printf("\n___Menu___");
        printf("\n1. Display");
        printf("\n2. Enqeue");
        printf("\n3. Deqeue");
        printf("\n4. Peek");
        printf("\n5. Is Empty");
        printf("\n6. Is Full");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            display(queue, front, rear);
            break;
        
        case 2:
            enqueue(queue, &front, &rear);
            break;

        case 3:
            dequeue(queue, &front, &rear);
            break;
        
        case 4:
            peek(queue, front, rear);
            break;

        case 5:
            if(isEmpty(front, rear)) {
                printf("\nQueue is empty.");
            } else {
                printf("\nQueue is not empty.");
            }
            break;

        case 6:
            if(isFull(rear)) {
                printf("\nQueue is full.");
            } else {
                printf("\nQueue is not full.");
            }
            break;
        
        case 7:
            printf("\nSuccessfully Exit");
            break;

        default: 
            printf("\nInvalid Input");
            break;
        }
    } while(choice != 7);
    return 0;
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("\nCannot display. Queue is Empty");
        return;
    }
    printf("\nDisplay Queue Items:");
    for(int i = front; i <= rear; i++) {
        printf("%d", queue[front]);
    } printf("\n");
}

void enqueue(int queue[], int *front, int *rear) {
    if (isFull(*rear)) {
        printf("\nEnqueue failed. Queue is Full.");
        return;
    } 
    if(*front == -1) {
        *front = 0;
    }
    int item;
    printf("\nEnter item: ");
    scanf("%d", &item);
    (*rear)++;
    queue[*rear] = item;
    printf("\nEnqueue completed. Item %d inserted in queue.", item);
}

void dequeue(int queue[], int *front, int *rear) {
    if(isEmpty(*front, *rear)) {
        printf("\nDequeue failed. Queue is Empty");
        return;
    }
    int item = queue[*front];
    (*front)++;
    if (*front > *rear) { 
        *front = -1;
        *rear = -1;
    }
    printf("\nDequeue completed. Item %d deleted from queue.", item);
}

void peek(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("\nPeek operation failed. Queue is Empty");
        return;
    }
    printf("\nPeek element is: %d", queue[front]);
}

int isEmpty(int front, int rear) {
    if(front > rear || front == -1) {
        return 1;
    }
    return 0;
}

int isFull(int rear) {
    if(rear == size - 1) {
        return 1;
    }
    return 0;
}
