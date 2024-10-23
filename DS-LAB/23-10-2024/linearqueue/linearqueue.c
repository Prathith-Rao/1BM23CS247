#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1, rear = -1;


int is_full() {
    return (rear == SIZE - 1);
}


int is_empty() {
    return (front == -1);
}


void insert(int value) {
    if (is_full()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)  
        front = 0;
    queue[++rear] = value;
    printf("Inserted %d into the queue.\n", value);
}


void delete() {
    if (is_empty()) {
        printf("Queue Underflow.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", queue[front]);
    front++;
    if (front > rear) {  
        front = -1;
        rear = -1;
    }
}

void display() {
    if (is_empty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;
    printf("\nQueue Operations:\n");
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
