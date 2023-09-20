#pragma once
#include <stdio.h>


enum Mois {jan = 1, fev, mars, avr, mai, juin, juil, aout, sept, oct, nov, dec};

struct Date { //3 cases réservées en memoire
int jour;
enum Mois mois;
int annee;
}; 


void initializeDate(struct Date *date);
void afficheDate(const struct Date *date);
struct Date creerDateParCopie();
struct Date* newDate();