#include <stdio.h>
#include "functions.c"

int tailleTableau();
void genererVecteur(int tailleVecteur);
int **genererMatrice(int tailleMatrice);
int **genererMatriceIdentite(int tailleMatrice);
int *calculeProduitMatriceVecteur(int **A, int *v);
int **calculerASigmaI(int **A, int **I, int sigma);
int **calculeTranspose(int **A);
int calculeNormeVecteur(int *v);
