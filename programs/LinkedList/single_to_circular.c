#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    temp->data=new_data;
    temp->next=*head_ref;
    *head_ref=temp;
}

struct Node* circular(struct Node* head)
{
    struct Node* start = head;
    struct Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=start;
    return head;
}

void PrintList(struct Node* node)
{
    struct Node* start = node;
    while(node->next!=start)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("%d",node->data);
}

int main()
{
    struct Node* head= NULL;
    push(&head, 15);
    push(&head, 14);
    push(&head, 13);
    push(&head, 22);
    push(&head, 17);
    head = circular(head);
    printf("Display List:\n");
    PrintList(head);
}