#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
}node;


node* createnode(int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->prev=NULL;
    newnode->next=NULL;
    newnode->data=data;
    return newnode;
}

struct node* createDoublyLinkedList() {
    return NULL;
}
int isempty(node* head){
    return head==NULL;
}

node* insert_at_beginning(int data, node* head){
    node* newnode=createnode(data);
    newnode->next=head;
    if(head!=NULL)
        head->prev=newnode;
    head=newnode;
    printf("%d has been successfully inserted.\n",data);
    return head;
}

node* insert_to_left(int data, int key, node* head) {
    node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }

    node* newnode = createnode(data);
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newnode;
    } else {
        head = newnode;
    }

    temp->prev = newnode;

    printf("%d has been successfully inserted left of %d\n", data, key);
    return head;
}


node* deletenode(int key,node* head){
    if(isempty(head)){
        printf("List is empty hence cannot delete a node\n ");
        return head;
    }
    node* temp=head;
    while(temp!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not found\n");
        return head;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("The node has been deleted\n");
    free(temp);
    return head;
}

void display(node* head){
    node* temp=head;
    if(isempty(head)){
        printf("List is empty\n");
        return;
    }
    printf("List elements : ");
    while(temp->next!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> NULL\n",temp->data);
}

int main() {
    node* head = createDoublyLinkedList();
    int choice, value, key;
    printf("\nDoubly Linked List Operations:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert to the left of a specific node\n");
    printf("3. Delete a node by value\n");
    printf("4. Display the list\n");
    printf("5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new value to insert: ");
                scanf("%d", &value);
                head=insert_at_beginning(value,head);
                break;
            case 2:
                if(!isempty(head)){
                    printf("Enter the key value: ");
                    scanf("%d", &key);
                    printf("Enter the new value to insert: ");
                    scanf("%d", &value);
                    head=insert_to_left(value,key,head);
                }
                else
                    printf("List is empty hence cannot insert to left.\n");
                break;

            case 3:
                if(!isempty(head)){
                    printf("Enter the value of the node to delete: ");
                    scanf("%d", &value);
                    head=deletenode(value,head);
                }
                else
                    printf("List is empty hence cannot delete.\n");
                break;

            case 4:
                display(head);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
