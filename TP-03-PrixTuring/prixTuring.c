/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

typedef struct {
int year;
char* name;
char* description; // on stocke l'adresse de la première case du tableau qui contient le nom du gagnant
} TuringWinner ; 

//attribuer 1024 au buffer (tableau temporaire), getc, on  arrive au ; on stock le bon nombre

int numberOfWinners(FILE *filename) {
	rewind(filename);
    if (filename==NULL)
        return 0;

    int nblines = 0;
    char c;

    while ((c = fgetc(filename)) != EOF) {
        if (c == '\n') {
            nblines++;
        }
    }
    return nblines;
}

char *readStringFromFileUntil(FILE *fp, char delim){
    int car;
    char *buffer = (char*) calloc(1024, sizeof(char)); //on alloue une place de 1024 qu'on enlève après
    int taille=0 ;

    while ((car = fgetc(fp)) != EOF && taille<1024) {
        if (car== delim)
		{
			buffer[taille]='\0';
			return buffer;
		}
		if (car != delim)
		{
			buffer[taille]=car;
			taille++;
		}
  };
	buffer[taille]='\0';
	char *result = (char*) calloc(taille, sizeof(char)); 
	for (int i = 0; i <= taille; i++){
		result[i]=buffer[i];
	}
	free(buffer);
    return result;
}


void readWinners(TuringWinner *winner, FILE *f) {
    fscanf(f,"%i;",&winner->year);
    winner->name=readStringFromFileUntil(f, ';');
    winner->description=readStringFromFileUntil(f, '\n');
}

void writeLine(TuringWinner *ligne, FILE *outputfile){
	fprintf(outputfile, "%d;", ligne->year);
	fprintf(outputfile, "%s;", ligne->name);
	fprintf(outputfile, "%s\n", ligne->description);
}

void delete(TuringWinner *ligne){
	free(ligne->name);	
	free(ligne->description);
	free(ligne);
}

TuringWinner* LigneWinner(FILE *f){
	TuringWinner *ligne = (TuringWinner*) malloc(sizeof(TuringWinner));
	readWinners(ligne, f);
	return ligne;
}

void printWinners(FILE* f, FILE *outputfile){
	TuringWinner *ligne;
	int nbWin = numberOfWinners(f);
	for (int i = 0; i < nbWin; i++)
	{
		ligne=LigneWinner(f);
		writeLine(ligne, outputfile);
		delete(ligne);
	}
}


TuringWinner* searchLineByAnnee(FILE* f, int annee){
	TuringWinner *ligne;
	int nbWin = numberOfWinners(f);
	for (int i = 0; i < nbWin; i++)
	{
		ligne=LigneWinner(f);
		if (ligne->year==annee)
		{
			return ligne;
		}
		delete(ligne);
	}
	return ligne;
}

void infoAnnee(FILE* f, int annee){
	TuringWinner *ligne = searchLineByAnnee(f, annee);
	if (ligne){
	printf("L'annee %i, le(s) gagnant(s) ont été : %s\nNature des travaux : %s\n", annee, ligne->name, ligne->description);
	delete(ligne);
	}
	else {
		printf("Aucune information pour cette année");
	}
}

int anneeMin(FILE *f, int yearAvant){
	TuringWinner *ligne;
	int nbWin = numberOfWinners(f);
	int anneeMin = 9999;
	for (int i = 0; i < nbWin; i++)
	{
		ligne=LigneWinner(f);
		if (yearAvant==0){
			if (ligne->year<anneeMin){
				anneeMin=ligne->year;
			}
		}
		if (ligne->year>yearAvant){
			if (ligne->year<anneeMin){
				anneeMin=ligne->year;
			}
		}
		delete(ligne);
	}
	return anneeMin;
}

void sortTuringWinnersByYear(FILE *f, FILE *sortedfile){
	TuringWinner *ligne;
	int nbWin = numberOfWinners(f);
	int yearAvant=0;
	int *pointyear=&yearAvant;
	int annee = anneeMin(f, yearAvant);
	int *pointannee=&annee;
	for (int i = 0; i < nbWin; i++)
	{
		ligne=searchLineByAnnee(f, annee);
		writeLine(ligne, sortedfile);
		delete(ligne);
		*pointyear= *pointannee; 
		*pointannee=anneeMin(f, yearAvant);
	}
}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
	char sortedFile[] = "sortedWinners.csv";
    FILE* f;
	FILE* outputfile;
	FILE* sortedfile;
    f = fopen(filename,"r");
	outputfile = fopen(outputFilename,"w");
	sortedfile = fopen(sortedFile,"w");


    printf("%i\n", numberOfWinners(f));
    printWinners(f, outputfile);
	sortTuringWinnersByYear(f, sortedfile);
	infoAnnee(f, 2022);
	sortTuringWinnersByYear(f, sortedfile);

	fclose(f);
	fclose(outputfile);
	fclose(sortedfile);

	return EXIT_SUCCESS;
}