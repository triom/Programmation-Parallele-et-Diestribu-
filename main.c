#include <stdio.h>
#include "header.h"

int main()
{
    //definir la suite de vecteur v et w
    //definir la matrice pleine
    //choisir un vecteur tel que la norme,||w1|| = 1
    //definir deux valeurs alpha et lamba
    //lamba= 0, alpha = 0
    //int *tableauValPropre
    //compteur = 0
    //tq  (|alpha - lamba| > 0)
    // w = A.v
    // alpha = argmax(w)
    //for(int i = 0; i< sizeof(w)+1;i++){
    /* v[i] = (1/alpha)* w[i]
                    }*/
    //lamba = alpha
    //alpha = 0
    //tableauValPropre[compteur]  = lamba
    //compteur +=1
    //fin tq
    // afficher lamda et le vecteur propre v pour chaque étepa et pour la fin aussi
    // int taille = tailleTableau();
    // int **A = genererMatrice(taille);
    // int *v, *w = genererVecteur(taille);
    // int lamba, alpha, compteur = 0;
    // int *tableauValPropre = NULL;
    // tableauValPropre = malloc(taille * sizeof(int));
    // while ((alpha - lamba) > 0)
    // {
    //     w = calculeProduitMatriceVecteur(A, v);
    //     alpha = 1;
    // }
    int *v = genererVecteur(5);
    int max = calculeArgMAx(v, 5);
    printf("\n%d", max);

    return 0;
}