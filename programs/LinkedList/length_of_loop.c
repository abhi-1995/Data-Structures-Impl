#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

int countNodes(struct Node* n)
{
    int res=1;
    struct Node* temp = n;
    while(temp->next!=n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

// Floyd's cycle Algorithm
int countNodesInLoop(struct Node* head)
{
    struct Node *slow_p=head, *fast_p=head;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p==fast_p)
        {
            return countNodes(slow_p);
        }
    }
    return 0;
}

int main()
{
    struct Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
 
    printf("%d \n", countNodesInLoop(head));
 
    return 0;
}