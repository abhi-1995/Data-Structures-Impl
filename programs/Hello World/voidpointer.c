#include<stdio.h>
int main() {
    int a = 1025;
    int *p;
    p = &a;
    printf("size of integer is %d bytes\n",sizeof(int));
    printf("Address = %d , value = %d\n",p,*p);
    // void pointer -- Generic Pointer -- Dereferencing
    // Couldn't be possible as void pointer doesn't refer
    // To any particular data type.
    void *p0;
    p0 = p;
    printf ("Size of void is %d \n", sizeof(void));
    printf("Address = %d, value=%d \n", p0+1);
    return 0;
}