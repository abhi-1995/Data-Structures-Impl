#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node
{
    int data;
    struct Node* next;
};

int isCircular(struct Node* head)
{
    clock_t t = clock();
    if (head == NULL)
    {
        return 1;
    }
    struct Node* ptr;
    ptr = head -> next;
    while(ptr != NULL && ptr != head)
    {
        ptr = ptr->next;
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Total Time taken by isCircular() %f seconds to complete\n",time_taken);
    return (ptr ==  head);
}

struct Node* newnode(int data)
{
    clock_t t = clock();
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next=NULL;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Total Time taken by newnode() %f seconds to complete\n",time_taken);
    return temp;
}

void PrintList(struct Node *head)
{
    printf("List:\n");
    struct Node* temp = head;
    clock_t t = clock();
    while(temp!=NULL)
    {
        if (temp->next==head)
        {
            printf("%d ",temp->data);
            break;
        }
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Total Time taken by PrintList() %f seconds to complete",time_taken);
    printf("\n");
}

int main()
{
    clock_t t;
    t = clock();
    struct Node* head= newnode(1);
    head->next= newnode(2);
    head->next->next= newnode(3);
    head->next->next->next= newnode(4);
    PrintList(head);
    if (isCircular(head))
    {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    // If not circular make circular
    head->next->next->next->next=head;
    PrintList(head);
    if (isCircular(head))
    {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    t = clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Total Time taken by main() %f seconds to complete\n",time_taken);
}