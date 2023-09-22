#include <stdio.h>
#include "dates.h"
#include <stdlib.h>
/*gcc -Wall -o dates dates.c
.\dates.exe*/

void initializeDate(struct Date* date) {
    printf("Entrez le jour : ");
    scanf("%d", &(date->jour)); // pareil que *d.jour, flèche fait référence a l'adresse
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", (int *)&date->mois);  // prend un entier et va directemment le stocker dans la case mémoire
    
    printf("Entrez l'annee : ");
    scanf("%d", &date->annee);
}

void afficheDate(struct Date* date) {
    printf("Date : %d %d %d\n", (*date).jour, (*date).mois,(*date).annee); // On cast l'enum Mois en int pour l'affichage
}

struct Date creerDateParCopie() {
    struct Date date;
    
    printf("Entrez le jour : ");
    scanf("%d", &date.jour);
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", (int *)&date.mois); 
    
    printf("Entrez l'annee : ");
    scanf("%d", &date.annee);
    
    return date;
}
//copie très lente si on a une structure lourde. Pour allouer une date on en a créé 2


struct Date* newDate() {  //retourne date*, adresse de la date créée
    struct Date* date = (struct Date*)malloc(sizeof(struct Date)); // malloc rertourne void*, je le transforme en date* car j'ai renseigné la taille d'une date, et je stock dans l'adresse d'une date 
    initialize(date);
    
    return date;
}