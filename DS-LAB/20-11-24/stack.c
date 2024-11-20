#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(struct Node** top) {
    return *top == NULL;
}

void push(struct Node** top, int data) {
    struct Node* node = createNode(data);
    node->next = *top;
    *top = node;
    printf("\nPushed %d",data);
}

int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}


void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("\nStack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;
    display(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);
    printf("Popped: %d", pop(&stack));
    display(stack);
    push(&stack, 40);
    display(stack);
    printf("\nPopped: %d", pop(&stack));
    printf("\nPopped: %d", pop(&stack));
    printf("\nPopped: %d", pop(&stack));
    display(&stack);
    return 0;
}
