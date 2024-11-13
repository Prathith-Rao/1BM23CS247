#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert node at the beginning
void insert_at_beginning(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Insert node at the end
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert node at a specific position
void insert_at_position(struct Node** head, int data, int position) {
    if (position < 0) return;  // Invalid position
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    struct Node* new_node = create_node(data);
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) return;  // Position out of range
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete node at the beginning
void delete_at_beginning(struct Node** head) {
    if (*head != NULL) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Delete node at the end
void delete_at_end(struct Node** head) {
    if (*head == NULL) return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next && temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Delete node with a specific key
void delete_at_key(struct Node** head, int key) {
    if (*head == NULL) return;
    if ((*head)->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) return;
    struct Node* to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
}

// Delete node before the key
void delete_before_key(struct Node** head, int key) {
    if (*head == NULL || (*head)->next == NULL) return;
    if ((*head)->next->data == key) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        if (temp->next->next->data == key) {
            struct Node* to_delete = temp;
            temp = temp->next;
            free(to_delete);
            return;
        }
        temp = temp->next;
    }
}

// Delete node after the key
void delete_after_key(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
        struct Node* to_delete = temp->next;
        temp->next = temp->next->next;
        free(to_delete);
    }
}

// Display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes to avoid memory leaks
void free_list(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int data, key;

    printf("Choice :\n1.insert_at_beginning\n2.insert_at_end\n3.insert_at_position\n4.delete_at_beginning\n5.delete_at_end\n6.delete_at_key\n7.delete_before_key\n8.delete_after_key\n9.display\n10.exit\n");

    int c;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_beginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the data and position: ");
                scanf("%d%d", &data, &key);
                insert_at_position(&head, data, key);
                break;
            case 4:
                delete_at_beginning(&head);
                break;
            case 5:
                delete_at_end(&head);
                break;
            case 6:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                delete_at_key(&head, key);
                break;
            case 7:
                printf("Enter the key to delete before: ");
                scanf("%d", &key);
                delete_before_key(&head, key);
                break;
            case 8:
                printf("Enter the key to delete after: ");
                scanf("%d", &key);
                delete_after_key(&head, key);
                break;
            case 9:
                display(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice...\n");
        }
    }
    return 0;
}

