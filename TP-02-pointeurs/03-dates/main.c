#include "dates.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    struct Date d;
    initialiseDate(&d); //Pourquoi a t-on ajouté un &? L'opérateur & est utilisé pour obtenir l'adresse mémoire de d. Cela permet à la fonction initialiseDate de modifier directement la structure d en utilisant cette adresse mémoire
    d=creerDateParCopie();
    struct Date *date;
    date = newDate();
    afficheDate(&d);
    free(date);
    return 0;
}