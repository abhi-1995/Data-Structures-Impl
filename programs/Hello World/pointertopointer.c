#include<stdio.h>
int main(){
    int x = 5;
    int* p = &x;
    printf("value ofx is %d \n",x);
    *p = 6;
    printf("value ofx is %d \n",x);
    int **q;
    q = &p;
    int ***r;
    r = &q;
    printf("Address of x is %d \n",&x);
    printf("Address of p is %d \n",p);
    printf("*p value is %d\n",*p);
    printf("*q value is %d\n",*q);
    printf("**q value is %d\n",**q);
    printf("**r value is %d\n",**r);
    printf("***r value is %d\n",***r);
    ***r = 110;
    printf("Value of X is %d",x);

}