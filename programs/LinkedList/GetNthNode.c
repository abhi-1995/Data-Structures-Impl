#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push_at_end(struct Node** head_ref, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    temp->data=data;
    temp->next=NULL;

    //First Time Entry
    if (*head_ref==NULL)
    {
        *head_ref = temp;
        return;
    }

    struct Node* ptr = *head_ref;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next=temp;

}

int GetNthNode(struct Node* head, int index)
{
    struct Node* current = head;
    int count=0;
    while(current!=NULL)
    {
        if (count==index)
        {
            return current->data;
        }
        count++;
        current = current->next;
    }
    return INT_MIN;
}

int main()
{
    struct Node* head = NULL;
    push_at_end(&head,10);
    push_at_end(&head,20);
    push_at_end(&head,30);
    push_at_end(&head,40);
    push_at_end(&head,50);
    push_at_end(&head,60);
    push_at_end(&head,70);
    int num;
    printf("For which index you retrieve the value?\n");
    scanf("%d",&num);
    int value = GetNthNode(head, num);

    if (value==INT_MIN)
    {
        printf("Size of the index is greater than the size of the list");
    }
    else
    {
        printf("Value found %d in index %d",value,num);
    }
}