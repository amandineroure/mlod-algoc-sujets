#include <stdio.h>
/*gcc -Wall -o dates dates.c
.\dates.exe*/

enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

struct Date {
int jour;
enum Mois mois;
int annee;
};

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

void initializeDate(struct Date *date) {
    printf("Entrez le jour : ");
    scanf("%d", &date->jour);
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", (int *)&date->mois); 
    
    printf("Entrez l'annee : ");
    scanf("%d", &date->annee);
}

void afficheDate(const struct Date *date) {
    printf("Date : %d %d %d\n", date->jour, (int)date->mois, date->annee); // On cast l'enum Mois en int pour l'affichage
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