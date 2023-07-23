#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void push_beg(struct Node** head_ref, int new_data)
{
    /**
     * Allocate Node
    */
   struct Node* temp = (struct Node*)malloc(sizeof(int));
   //Put the new key
   temp->data=new_data;
   //Link the Old List of the new node
   temp->next = (*head_ref);

   //Move the head to point the new node
   *head_ref = temp;
}

bool search(struct Node* head, int x) {
    struct Node* current = head;
    while(current != NULL)
    {
        if(current->data==x)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

int getCount(struct Node* head) {
    struct Node* current = head;
    int counter=0;
    while(current != NULL) {
        counter++;
        current = current->next;
    }
    return counter;
}

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    int x = 21;

    push_beg(&head, 10);
    push_beg(&head, 30);
    push_beg(&head, 11);
    push_beg(&head, 21);
    push_beg(&head, 14);
     
      // Function call
    search(head, x) ? printf("Yes") : printf("No");
    printf("\n");
    printf("Length Of the Linked List is: %d",getCount(head));
    return 0;
}