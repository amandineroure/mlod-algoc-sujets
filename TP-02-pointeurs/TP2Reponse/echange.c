#include <stdio.h>
/*gcc -Wall -o echange echange.c
.\echange.exe*/

int main(void){
    int a=10;
    int b=20;
    echangeContenu(&a, &b);
    printf("%d ",a);
    printf("%d", b);
}
int echangeContenu(int *a, int *b){
    int c=a;
    a=b;
    b=c;
}