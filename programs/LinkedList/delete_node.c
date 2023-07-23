#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void deleteFirst(struct Node** head)
{
    struct Node* temp = *head;
    *head = temp -> next;
    free(temp);
}

void deleteEnd(struct Node** head)
{
    struct Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=NULL;
    free(temp);
}

void deleteNode(struct Node** head, int key)
{
    struct Node *temp = *head;
    struct Node *prev;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp -> data != key)
    {
        prev = temp;
        temp = temp -> next;
    }

    if (temp == NULL) return;

    // Remove the Node
    prev-> next = temp->next;

    free(temp);
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
    struct Node* temp = head;
    printf("List is:");
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
    printf("BEFORE DELETING THE LINKED LIST....");
    Print(head);
    printf("Enter the value to be deleted?\n");
    int num;
    scanf("%d", &num);
    deleteNode(&head,num);
    printf("BEFORE DELETING THE VALUE %d FROM THELINKED LIST....\n",num);
    Print(head);
    printf("AFTER DELETING THE LINKED LIST FROM BEGINING....\n");
    deleteFirst(&head);
    Print(head);
    printf("AFTER DELETING THE LINKED LIST FROM END....\n");
    deleteEnd(&head);
    Print(head);
}
