/* Mon programme Hello World */
#include <stdio.h>

int nombresparfaits(int nb){
    int i =1;
    for (i=1; i<=nb;i++)
    {
        int s=0;
        int j=1;
        for (j=1; j<i; j++)
        {
            if (i%j==0)
            {s+=j;
            }
        }
        if (s==i){
            printf("%d\n", i);
        }
    }
    return 0;
}

int main(void) {
printf("Hello wtf !\n"); // Affichage sur la sortie standard
nombresparfaits(512);
return 0;
}
