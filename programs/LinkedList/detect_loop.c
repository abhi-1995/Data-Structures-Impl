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

// Floyd's cycle Algorithm
bool detectCycle(struct Node* head)
{
    struct Node *slow_p=head, *fast_p=head;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p==fast_p)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head->next;

    if (detectCycle(head))
    {
        printf("CYCLE DETECTED\n");
    }else{
        printf("NO CYCLE FOUND\n");
    }

}