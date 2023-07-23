#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert_end(struct Node* start) {
    struct Node* temp = (struct Node*)malloc(sizeof(int));
    int num;
    printf("Enter the data\n");
    scanf("%d", &num);
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

void Print(struct Node *head) {

    printf("List is:");
    while(head != NULL) {
        printf(" %d", head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insert_end(head);
    head = insert_end(head);
    head = insert_end(head);
    head = insert_end(head);
    Print(head);
}