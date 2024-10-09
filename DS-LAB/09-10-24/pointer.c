#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void push(int a, int* stack, int* top) {
    if (*top == SIZE - 1) {
        printf("\nStack is full, overflow condition");
    } else {
        (*top)++;
        stack[*top] = a;
        printf("\nElement %d successfully pushed to stack", a);
    }
}

void pop(int* stack, int* top) {
    if (*top == -1) {
        printf("\nStack is empty, underflow condition");
    } else {
        int ele = stack[*top];
        printf("\nElement %d has been successfully popped", ele);
        (*top)--; 
    }
}

void display(int* stack, int* top) {
    if (*top == -1) {
        printf("\nStack is empty, underflow condition");
    } else {
        printf("\nStack elements are: ");
        for (int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {  
    int stack[SIZE]; 
    int top = -1;
    int c, e;

    while (1) {
        printf("\n\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("\nEnter the element to push: ");
                scanf("%d", &e);
                push(e, stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            case 4:
                exit(0); 
            default:
                printf("\nInvalid input");
        }
    }

    return 0;  
}
