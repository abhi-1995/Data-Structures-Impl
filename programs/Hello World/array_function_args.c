#include<stdio.h>
int SumOfElements(int* A,int size) {
    /**
     * Size of the array will not be known to us as the value pass is pointer
     *  A is pointer to integer
     * printf("SOE() size of A id %d\n",sizeof(A[0]));
     * 'sizeof' on array function parameter 'A' will return size of 'int *'
     * Array arguments always call by reference.
    */  
    int i, sum=0;
    for (i=0;i<size; i++) {
        sum += *(A+i); //A[i]
    }
    return sum;
}

void Double(int A[], int size) {
    int i;
    for(i=0; i<size; i++) {
        A[i] = 2*A[i];
    }
}

int main() {
    int A[] = {1,2,3,4,5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = SumOfElements(A,size);
    printf("Sum of all elements = %d \n",total);
    Double(A,size);
    int k;
    for(k=0; k<size; k++) {
        printf ("%d ",A[k]);
    }
}