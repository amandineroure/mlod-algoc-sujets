#include <stdio.h>
#include <dates.h>
/*gcc -Wall -o dates dates.c
.\dates.exe*/

void initializeDate(struct Date *date) {
    printf("Entrez le jour : ");
    scanf("%d", &date->jour);
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", (int *)&date->mois); 
    
    printf("Entrez l'annee : ");
    scanf("%d", &date->annee);
}

void afficheDate(const struct Date *date) {
    printf("Date : %d %d %d\n", &date->jour, (int)&date->mois, &date->annee); // On cast l'enum Mois en int pour l'affichage
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