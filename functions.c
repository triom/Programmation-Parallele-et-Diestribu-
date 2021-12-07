#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MIN 2


int tailleTableau(){
    int taille;
    srand(time(NULL));
    //recuperer la taille de la matrice à generer
    taille = (rand() % (MAX - MIN + 1) + MIN) ;
    printf("%d\n",taille);
    return taille;
}

void genererVecteur(int tailleVecteur){
    //declarer le vecteur
    int *v;
    //allocation dynamique de la memoire pour le vecteur
    v = (int*)malloc(tailleVecteur* sizeof(int));
    //verifier que l'allocationa reussi et remplir le vecteur
    if(v== NULL){
        printf("Allocation echouée");
    }
    else {
        for(int i=0; i< tailleVecteur;i++){
            v[i] = (rand() % ((MAX )- MIN + 1) + MIN);
        }
    }

    for(int j=0; j< tailleVecteur;j++){
        printf("%d, ", v[j]);
    }

    free(v);
}


void genererMatrice(int tailleMatrice){
    //declarer la matrice
    int *A;
    //allocation dynamique de la memoire pour la matrice
    A = (int*)malloc((tailleMatrice * tailleMatrice) * sizeof(int));
    //verifier que l'allocationa reussi et remplir la matrice
    if(A == NULL){
        printf("Allocation echouée");
    }
    else {
        for(int i=0; i< tailleMatrice * tailleMatrice; i++){
            A[i] = (rand() % ((MAX )- 0 + 1) +0);
        }
    }

    for(int j=0; j< tailleMatrice * tailleMatrice; j++){
        printf("%d ", A[j]);
        if((j+1)%tailleMatrice == 0 ){
            printf("\n");
        }
    }

    free(A);

}



