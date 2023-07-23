#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* Reverse(struct Node* head) {
    struct Node *current,*prev,*next;
    current = head;
    prev=next=NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current = next;
    }
    head=prev;
    return head;
}

struct Node* insert_end(struct Node* start, int num) {
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    temp->data=num;
    temp->next=NULL;
    struct Node* ptr = start;
    if (ptr == NULL){
        start = temp;
        return start;
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return start;
}

void Print(struct Node *head) {

    printf("List is:");
    struct Node* temp = head;
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    head = insert_end(head,1);
    head = insert_end(head,2);
    head = insert_end(head,3);
    head = insert_end(head,4);
    head = insert_end(head,5);
    printf("Before Reverse the List:\n");
    Print(head);
    head = Reverse(head);
    printf("After Reverse the List:\n");
    Print(head);
}