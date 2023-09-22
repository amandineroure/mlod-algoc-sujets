#pragma once
#include <stdint.h>
typedef struct {
  uint16_t nblignes;
  uint16_t nbcolonnes;
  int64_t** valeurs;
}Matrice;

Matrice* creer(int v, int l, int c);
void initialiserLigne(int v, int l, Matrice* mat);
Matrice* multiplier(Matrice* A, Matrice* B);
void matrix_print(Matrice* mat) ;