//ROURE Amandine
//gcc arnm.c  -o main
//./main*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "vaccins_covid.h"

// =========
// = Types =
// =========

const char NUCLEOTIDES[] = "ATCG";

typedef struct {
	int index;
	int distance;

}typeDifference;

// =============
// = Fonctions =
// =============

int* statistics(char c[]){
	int *tab = (int*)malloc
	int tab[4]={0,0,0,0};
	int *p=&tab;
	int i=0;
	char m=c[i];
	while (m!='\0'){	
		if (m=='A'){
			tab[0]+=1;
		}
		else if (m=='T'){
			tab[1]+=1;
		}
		else if (m=='C'){
			tab[2]+=1;
		}
		else if (m=='G'){
			tab[3]+=1;
		}
		i++;
		m=c[i];
	}
	return p;
}



bool isNucleotide(char c) {
    return (c==NUCLEOTIDES[0] || c==NUCLEOTIDES[1] || c==NUCLEOTIDES[2] || c==NUCLEOTIDES[3]);
}

int indexOf(char nucleotide) {
	switch(nucleotide) {
		case 'A': return 0;
		case 'T': return 1;
		case 'C': return 2;
		case 'G': return 3;
		default:
			return -1;
	}
}

int distanceBetweenNucleotides(char n1, char n2) {
    return indexOf(n1)-indexOf(n2);
}

typeDifference** computeDifferencesBetween(char s1[], char s2[]){
	typeDifference **td=(typeDifference**)calloc(len(s1), sizeof(typeDifference*));
	int taille=0;
	int i=0;
	char m=s1[i];
	while(m!='\0'){
		char m=s1[i];
		char n=s2[i];
		if (m!=n){
			typeDifference *tab=(typeDifference*)malloc(sizeof(typeDifference));
			tab->index=i;
			tab->distance = distanceBetweenNucleotides(m, n);
			td[taille]=tab;	
		}
	i++;
		
	}
	typeDifference **result=(typeDifference**)calloc(taille, sizeof(typeDifference*));
	for (int j=0; j<taille;j++){
		result[j]=td[j];
	}
	return result;
}

void printDifference(typeDifference **tab){
	int n=len(*tab);
	printf("Les différences sont : \n");
	for (int i=0;i<n;i++){
		int ind = tab[i]->index;
		int dist = tab[i]->distance;
		printf("<%d,%d>\n",ind, dist);
	}

}

// ========
// = Main =
// ========

int main(void){

	char sequenceDeNucleotides[]="ATGCATCCATCATGCATGTA";

    printf("%s\n",code_proteine_spike_moderna);

	return EXIT_SUCCESS;
}

