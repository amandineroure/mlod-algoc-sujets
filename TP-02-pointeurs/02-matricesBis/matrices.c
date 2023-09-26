#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrices.h"
/*gcc -Wall -o matrices matrices.c
.\matrices.exe*/

Matrice* creer(int v, int l, int c){
    Matrice* mat = (Matrice*)malloc(sizeof(Matrice));
    mat->nblignes = l;
    mat->nbcolonnes = c;
    int64_t** val = (int64_t**)malloc(l*sizeof(int64_t*));
    mat->valeurs=val;
    for (int i=0; i<l; i++){
        int64_t* pl = (int64_t*)malloc(c*sizeof(int64_t));
        val[i]=pl;
        for (int j=0; j<c;j++){
            val[i][j]=v;
        }
    }
    return mat;
}

void initialiserLigne(int v, int l, Matrice* mat){
    for (int i=0; i<mat->nbcolonnes;i++){
        (mat->valeurs)[l][i]=v;
    }
}

Matrice* multiplier(Matrice* A, Matrice* B){
    Matrice* C=creer(0, A->nblignes, B->nbcolonnes);

    for (int i=0; i<A->nblignes; i++)
    {
        for (int j=0; j<B->nbcolonnes; j++)
        {
            for (int k=0; k< A->nbcolonnes; k++)
            {
                (C->valeurs)[i][j]+=(A->valeurs)[i][k]*(B->valeurs)[k][j];
            }
        }
    }
    return C;
}


void matrix_print(Matrice* mat) {
    for (int i = 0; i < mat->nblignes; i++) {
        for (int j = 0; j < mat->nbcolonnes; j++) {
            printf("%ld ", (mat->valeurs)[i][j]);
        }
        printf("\n");
        }
    printf("\n");
}

void detruire(Matrice* mat){
    for (int i = 0; i < mat->nblignes; i++)
  {
    free((mat->valeurs)[i]);
  }
  free(mat->valeurs);
  free(mat);
  mat=NULL;

}
/*b. On peut la réutiliser en changeant la taille (SIZE), et vu qu'on a spécifier qu'une seule dimension, le code est déjà plus globale
c. l'utilisateur peut saisir la taille au début, ou alor créer une matrice plus grace, la parcourir pour la réduire*/