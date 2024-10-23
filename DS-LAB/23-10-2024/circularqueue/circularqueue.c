#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;


int is_full() {
    return (front == (rear + 1) % SIZE);
}


int is_empty() {
    return (front == -1);
}


void insert(int n) {
    if (is_full()) {
        printf("Queue Overflow\n");
        return;
    }
    if (is_empty())  
        front = 0;
        rear = 0;
    else
        rear = (rear + 1) % SIZE;
    queue[rear] = n;
    printf("Element %d inserted.\n", n);
}


void delete() {
    if (is_empty()) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Element %d deleted\n", queue[front]);
    if (front == rear){
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % SIZE;
}


void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("\nCircular Queue Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
