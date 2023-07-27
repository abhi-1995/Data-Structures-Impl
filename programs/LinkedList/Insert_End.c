#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* GetNewNode(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(int));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;

}

struct Node* insert_end(struct Node* head, int new_data) {
    struct Node* new_node = GetNewNode(new_data);
    if (head == NULL){// first time entry
        head= new_node;
        return head;
    }
    struct Node* ptr = head;
    while(ptr->next != NULL) {// to fetch the last node
        ptr = ptr->next;
    }
    // ptr is head
    ptr->next = new_node;// assign last node to new node
    return head;
}

void Print(struct Node *head) {

    printf("List is:");
    while(head != NULL) {
        printf(" %d", head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insert_end(head,10);
    head = insert_end(head,20);
    head = insert_end(head,30);
    head = insert_end(head,40);
    Print(head);
}