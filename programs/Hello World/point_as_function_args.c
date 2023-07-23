#include<stdio.h>

void IncrementCalledByValue(int a) {
    /*Increment(args a) --> called function
      args a --> Formal Argument
    */
   printf("Inside calledByValue()\n");
   printf("Before Adding a is %d \n",a);
    a = a + 1;
    printf("After Adding a is %d \n",a);
    printf("Address of a in IncrementCalledByValue() : %d\n",&a);
}

void IncrementCalledByReference(int *p) {
    printf("Inside calledByValue()\n");
    printf("Address of a/*p in IncrementCalledByReference() : %d\n",p);
    printf("Before Adding a is %d \n",*p);
    *p = (*p) + 1;
    printf("After Adding a is %d \n",*p);
    
}

int main() {
    /**
     * main() : calling function
     * 
    */
    int a;
    a = 10;
    IncrementCalledByValue(a); // args a ->> Actual Argument
    //Called By Value
    printf("Address of a in main() : %d\n",&a);
    printf("a (called by value) = %d \n",a);
    IncrementCalledByReference(&a); // Called By reference
    printf("a (called by reference) = %d \n",a);
}