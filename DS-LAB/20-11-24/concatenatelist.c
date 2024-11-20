#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (!head) return newNode;

    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    struct Node* temp = head1;
    while (temp->next) temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int choice, value;

    printf("Creating List 1:\n");
    do {
        printf("Enter value to insert (-1 to stop): ");
        scanf("%d", &value);
        if (value != -1) list1 = insertAtEnd(list1, value);
    } while (value != -1);

    printf("Creating List 2:\n");
    do {
        printf("Enter value to insert (-1 to stop): ");
        scanf("%d", &value);
        if (value != -1) list2 = insertAtEnd(list2, value);
    } while (value != -1);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    list1 = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    printList(list1);

    return 0;
}
