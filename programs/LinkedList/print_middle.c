#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void push_end(struct Node** head_ref, int new_data)
{
    struct Node* temp = (struct Node*) malloc(sizeof(int));
    temp->data=new_data;
    temp->next=NULL;
    struct Node* ptr = *head_ref;
    if (ptr==NULL)
    {
        *head_ref = temp;
        return;
    }
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=temp;
    
}

void PrintMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL)
    {
        while(fast_ptr != NULL && fast_ptr->next!=NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The Middle Element is [%d]\n\n", slow_ptr->data);
    }
}

void Print(struct Node *head)
{
    struct Node* ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr -> next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    push_end(&head,10);
    push_end(&head,20);
    push_end(&head,30);
    push_end(&head,40);
    Print(head);
    PrintMiddle(head);
    push_end(&head,50);
    Print(head);
    PrintMiddle(head);
    
}