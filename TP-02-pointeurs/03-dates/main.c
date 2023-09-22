#include "dates.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/*gcc main.c .\dates.c -o main
./main*/


int main(void) {
    struct Date d;
    initializeDate(&d); //Pourquoi a t-on ajouté un &? L'opérateur & est utilisé pour obtenir l'adresse mémoire de d. Cela permet à la fonction initialiseDate de modifier directement la structure d en utilisant cette adresse mémoire
     afficheDate(&d);
    d=creerDateParCopie();
     afficheDate(&d);
    struct Date *date;
    date = newDate();
    afficheDate(&d);
    free(date);  //des qu'il y a un malloc il faut un free
    return 0;
}