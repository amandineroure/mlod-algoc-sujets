#include "matrices.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
/*gcc main.c .\matrices.c -o main
./main*/

int main(void) {
Matrice *A, *B, *C;
Matrice *AmultB;
A = creer(1, 2, 3); // valeurInitiale, nbreLignes, nbreColonnes
B = creer(1, 3, 3);
initialiserLigne(2, 1, A);
initialiserLigne(2, 2, B);
C = multiplier(A, B);
matrix_print(C);
}