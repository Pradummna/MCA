// Stack all operations: Push, Pop, Peek, isEmpty, isFull
#include<stdio.h>
#define size 100

// Function prototypes
void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
int isEmpty(int top);
int isFull(int top);
void display(int stack[], int top);

int main() {
    int stack[size], top = -1, choice;
    printf("Stack All Operations");

    do {
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. isEmpty");
        printf("\n5. isFull");
        printf("\n6. Display");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                push(stack, &top);
                break;
            }
            case 2: {
                pop(stack, &top);
                break;
            }
            case 3: {
                peek(stack, top);
                break;
            }
            case 4: {
                if (isEmpty(top)) {
                    printf("\nStack is Empty");
                } else {
                    printf("\nStack is not Empty");
                }
                break;
            }
            case 5: {
                if (isFull(top)) {
                    printf("\nStack is Full");
                } else {
                    printf("\nStack is not Full");
                }
                break;
            }
            case 6: {
                display(stack, top);
                break;
            }
            case 7: 
                printf("\nSuccessfully Exited.");
                break;
            default:
                printf("\nWrong Input! Please choose a valid option.");
                break; 
        }
    } while (choice != 7);

    return 0;
}

// Stack push operation
void push(int stack[], int *top) {
    if (*top >= size - 1) {
        printf("\nStack is Full! Cannot push new element.");
    } else {
        int data;
        printf("\nEnter integer data: ");
        scanf("%d", &data);
        (*top)++;
        stack[*top] = data;
        printf("\n%d successfully Inserted into the stack.", data);
    }
}

// Stack pop operation
void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack is Empty! Cannot pop an element.");
    } else {
        printf("\nItem successfully deleted: %d", stack[*top]);
        (*top)--;
    }
}

// Stack peek operation
void peek(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is Empty! No top element.");
    } else {
        printf("\nTop element is: %d", stack[top]);
    }
}

// Check if stack is empty
int isEmpty(int top) {
    return (top == -1);
}

// Check if stack is full
int isFull(int top) {
    return (top >= size - 1);
}

// Display stack elements
void display(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is Empty! No elements to display.");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
