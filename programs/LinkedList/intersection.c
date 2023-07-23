#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* insert_end(struct Node* start,int num) {
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

void listIntersection(struct Node* list1, struct Node* list2)
{
    struct Node* intersecthead = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data == list2->data)
        {
            intersecthead = insert_end(intersecthead,list1->data);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->data < list2->data)
        {
            list1 = list1->next;
        }
        else
        {
            list2 = list2 -> next;
        }
    }

    printf("Intersection Of List1 & List2 is:\n");

    Print(intersecthead);

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
    struct Node* head1 = NULL;

    head1 = insert_end(head1,1);
    head1 = insert_end(head1,2);
    head1 = insert_end(head1,3);
    head1 = insert_end(head1,4);
    head1 = insert_end(head1,5);
    head1 = insert_end(head1,199);
    head1 = insert_end(head1,201);
    head1 = insert_end(head1,200);

    struct Node* head2 = NULL;

    head2 = insert_end(head2,1);
    head2 = insert_end(head2,4);
    head2 = insert_end(head2,5);
    head2 = insert_end(head2,35);
    head2 = insert_end(head2,100);
    head2 = insert_end(head2,198);
    head2 = insert_end(head2,201);
    
    printf("List1:\n");
    Print(head1);

    printf("List2:\n");
    Print(head2);

    free(head1);
    free(head2);

    listIntersection(head1,head2);


    

}