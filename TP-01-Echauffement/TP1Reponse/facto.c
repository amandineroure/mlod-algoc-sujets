#include <stdio.h>
/*gcc -Wall -o facto facto.c
.\facto.exe*/

typedef unsigned long long TypeEntier;
TypeEntier factorielle(TypeEntier nb)
{
    TypeEntier i=1;
    TypeEntier f=1;
    for (i=1;i<=nb;i++)
    {
        f=f*i;
    }
    return f;
}

void bouclefacto(TypeEntier nb)
{
    TypeEntier i =1;
    for (i=1; i<=nb; i++)
    {
        printf("%llu\n",factorielle(i));
    }
}

int main(void) {
bouclefacto(15);
return 0;
}


