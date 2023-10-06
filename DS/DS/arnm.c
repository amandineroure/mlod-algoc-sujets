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

int* statistics(char* c){
	int n = strlen(c);
	int* tab= calloc(sizeof(int), 4);
	for(int i=0; i<n; i++){
		char m=c[i];
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
	}
	for(int i=0; i<4; i++){
		tab[i] = (tab[i]*100)/n;
	}
	return tab;
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

typeDifference** computeDifferencesBetween(const char s1[], const char s2[]){
	int n =strlen(s1);
	int taille=0;
	for (int i=0; i<n;i++){
		char m=s1[i];
		char n=s2[i];
		if (m!=n){
			taille++;
		}
	}
	typeDifference **result=(typeDifference**)calloc(taille,sizeof(typeDifference*));
	int index_diff=0;
	for(int i=0; i<n; i++){
		char m=s1[i];
		char n=s2[i];
		printf("hello");
		if (m!=n && index_diff<taille){
			result[index_diff]->index=i;
			result[index_diff]->distance = distanceBetweenNucleotides(n, m);
			index_diff++;
			printf("salut");
		}

	}
	printf("yo");
	return result;
}


void printDifference(typeDifference **tab){
	int n=sizeof(*tab);
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
    //printf("%s\n",code_proteine_spike_moderna);
	typeDifference **dif=computeDifferencesBetween(code_proteine_spike_pfizer, code_proteine_spike_moderna);
	printDifference(dif);
	return EXIT_SUCCESS;
}

