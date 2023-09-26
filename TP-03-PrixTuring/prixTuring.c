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
unsigned int year;
char* name;
char* description; // on stocke l'adresse de la première case du tableau qui contient le nom du gagnant
} TuringWinner ; 

//attribuer 1024 au buffer (tableau temporaire), getc, on  arrive au ; on stock le bon nombre

int numberOfWinners(FILE *filename) {
    if (filename==NULL)
        return 0;

    int lines = 0;
    char c;

    while ((c = fgetc(filename)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    return lines;
}

char *readStringFromFileUntil(FILE *fp, char delim){
    char *buffer = NULL;
    size_t bufferSize = 1024;
    int character;
    size_t length = 0;

    while ((character = fgetc(fp)) != EOF && character != delim) {
        if (length + 1 >= bufferSize) {
            bufferSize *= 2; 
            char *newBuffer = realloc(buffer, bufferSize);
            if (newBuffer == NULL) {
                free(buffer);
                perror("Erreur lors de la réallocation de mémoire.");
                return NULL;
            }
            buffer = newBuffer;
        }
        buffer[length++] = (char)character;
    }

    if (length > 0) {
        buffer[length] = '\0';
    } else {
        buffer = malloc(1);
        if (buffer == NULL) {
            perror("Erreur lors de l'allocation de mémoire.");
            return NULL;
        }
        buffer[0] = '\0';
    }

    return buffer;
}

TuringWinner* readWinner(FILE *f) {


}

void readWinners(TuringWinner *winner, FILE *f) {
    fscanf(f,"%i"";",&winner->year);
    winner->name=readStringFromFileUntil(f,";");
    winner->description=readStringFromFileUntil(f,"\n");
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";
    FILE* f;
    FILE* of;
    f = fopen(filename,"r");
	of = fopen(outputFilename,"a");

    

	//copie(fpname, outputFilename);
    printf("%i", numberOfWinners(f));

    TuringWinner turingWinner = readWinner(f);
    //turingWinner=...;

	return EXIT_SUCCESS;
}