#include <stdio.h>
#include "functions.c"

int tailleTableau();
int *genererVecteur(int tailleVecteur);
int **genererMatrice(int tailleMatrice);
int **genererMatriceIdentite(int tailleMatrice);
int *calculeProduitMatriceVecteur(int **A, int *v);
int **calculerASigmaI(int **A, int **I, int sigma);
int **calculeTranspose(int **A); // a verifier
int calculeNormeVecteur(int *v);
int calculeArgMAx(int *v, int size_V);
