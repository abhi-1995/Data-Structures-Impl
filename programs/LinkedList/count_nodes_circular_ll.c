#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

/* Function to insert a node at the beginning of a Circular
   linked list */

void push(Node **head_ref, int data)
{
    Node* ptr1 = (Node *)malloc(sizeof(int));
    Node* temp = *head_ref;
    ptr1->data=data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)  
    {
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next=ptr1;
        
    }
    else
    {
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
    
}


int countNodes(Node* head)
{
    Node *temp = head;
    int c=0;
    if (head != NULL)
    {
        do
        {
            temp = temp->next;
            c++;
        } while (temp != head);
        
    }
    return c;
}

int main()
{
    /* Initialize lists as empty */
    Node* head = NULL;
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    printf("%d", countNodes(head));
    return 0;
}