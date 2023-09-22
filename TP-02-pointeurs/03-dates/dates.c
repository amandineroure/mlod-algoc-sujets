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


struct Date* newDate() {
    struct Date* date = (struct Date*)malloc(sizeof(struct Date));
    printf("Entrez le jour : ");
    scanf("%d", &date->jour);
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", (int *)&date->mois); // On cast l'enum Mois en int pour scanf
    
    printf("Entrez l'annee : ");
    scanf("%d", &date->annee);
    
    return date;
}