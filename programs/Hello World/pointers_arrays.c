//Pointers and Arrays
/**
 * Element at Index i
 * Address --> &A[i] or (A + i)
 * Value --> A[i] or *(A + i)
*/
#include<stdio.h>
int main() {
    int A[] = {2,4,5,8,1};
    int i;
    int *p = A;
    for (i=0; i<5; i++){
        printf("For i = %d\n",i);
        printf("%d\n",&A[i]);
        printf("%d\n",(A + i));
        printf("%d\n",A[i]);
        printf("%d\n",*(A+i));
    }
}