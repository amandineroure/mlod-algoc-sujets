#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
/*gcc -Wall -o matrices matrices.c
.\matrices.exe*/

int main(void) {
//matrices en ligne * colonne
int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
int64_t matriceResultat[SIZE][SIZE];
matrix_mult(matriceResultat,matrice1,matrice2);
matrix_print(matriceResultat);
return EXIT_SUCCESS;
}

void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]){
    for (int i=0; i< SIZE; i++)
    {
        for (int j=0; j< SIZE; j++)
        {
            matriceResultat[i][j]=0;
            for (int k=0; k< SIZE; k++)
            {
                matriceResultat[i][j]+=matrice1[i][k]*matrice2[k][j];
            }
        }
    }
}

void matrix_print(int64_t mat[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%ld ", mat[i][j]);
        }
        printf("\n");
        }
}

/*b. On peut la réutiliser en changeant la taille (SIZE)
c. l'utilisateur peut saisir la taille au début, ou alor créer une matrice plus grace, la parcourir pour la réduire*/