#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* GetIntersectionNode(struct Node* head1, struct Node* head2)
{
   // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
 
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;
 
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
 
        if (ptr1 == ptr2)
            return ptr1;
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1;
}


void PrintList(struct Node* head)
{
    if (head == NULL)
    {
       printf("Empty List");
       return;
    }
    
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node* newNode;

    struct Node* head1 = (struct Node*)malloc(sizeof(int));
    head1->data=10;

    struct Node* head2 = (struct Node*)malloc(sizeof(int));
    head2->data=3;

    newNode = (struct  Node*)malloc(sizeof(int));
    newNode->data=6;
    head2->next=newNode;

    newNode = (struct Node*)malloc(sizeof(int));
    newNode->data=9;
    head2->next->next=newNode;

    newNode = (struct  Node*)malloc(sizeof(int));
    newNode->data=15;
    head1->next = newNode;
    head2->next->next->next=newNode;

    newNode = (struct Node*)malloc(sizeof(int));
    newNode->data = 30;
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;

    printf("List1:\n");
    PrintList(head1);

    printf("List2:\n");
    PrintList(head2);
    struct Node* inter_ptr = GetIntersectionNode(head1,head2);
    PrintList(inter_ptr);

}
