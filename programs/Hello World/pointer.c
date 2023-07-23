#include<stdio.h>

int main() {

    int a;
    int *p;
    a = 10;
    p = &a; // &a = address of a
    printf("%d\n",p);
    printf("%d\n", &a);
    printf("%d\n",a);
    printf("%d\n",*(p));
    *p = 12; //dereferencing
    printf("%d\n",a);
    int b = 20;
    p = &b;
    printf("Address of P is %d\n",p);
    printf("Value at P is %d\n", *p);
    printf("Value at b is %d\n",b);
    return 0;
}