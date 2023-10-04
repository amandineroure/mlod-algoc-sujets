#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a==NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a=NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a=(ArbreBinaire) malloc(sizeof(Noeud));
	a->val=e;
	initialiser(&a->filsGauche); 
	initialiser(&a->filsDroit);
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	if (estVide(a))	{
		return creer(e);
	}
	ArbreBinaire actuel = a;
	ArbreBinaire suivant;
	bool elementPlusPetit = a->val>e;
	if (a->val==e){
			return a;
	}
	if (elementPlusPetit){
		suivant=a->filsGauche;
	}
	else	{
		suivant=a->filsDroit;
	}

	while (!estVide(suivant)){
		if (suivant->val==e){
			return a;
		}
		elementPlusPetit = suivant->val>e;
		if (elementPlusPetit){
			actuel = suivant;
			suivant=suivant->filsGauche;
		}
		else{
			actuel = suivant;
			suivant=suivant->filsDroit;
		}
	}
	if (elementPlusPetit){
			actuel->filsGauche=creer(e);
		}
		else{
			actuel->filsDroit=creer(e);
		}
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	if (estVide(a)){
		a = creer(e);
		return a;
	}
	else if (a->val==e){
		return a;
	}
	else if (a->val<=e){
		a->filsDroit=insere_r(a->filsDroit, e);
		return a;
	}
	else if (a->val>e){
		a->filsGauche=insere_r(a->filsGauche, e);
		return a;
	}
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if (estVide(a)){
		return 0;
	}
	else if (a->filsDroit == NULL && a->filsGauche == NULL){
		return 1;
	}
	return 1+nombreDeNoeud(a->filsDroit)+nombreDeNoeud(a->filsGauche);
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	if (estVide(a)){return -1;}
	else if (a->val==e){
		return 0;
	}
	else if (a->val<=e){
		return profondeur(a->filsDroit, e);
	}
	else if (a->val>e){
		return profondeur(a->filsGauche, e);
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if (estVide(a)){
		return 0;
	}
	else if (a->val!=NULL && a->filsDroit != NULL && a->filsGauche != NULL){
		return 1;
	}
	if (hauteur(a->filsDroit)>=hauteur(a->filsDroit)){
		return hauteur(a->filsDroit)+1;
	}
	else {
		return hauteur(a->filsGauche)+1;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){

	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
}

void afficheGRD_r(ArbreBinaire a){
}

void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

