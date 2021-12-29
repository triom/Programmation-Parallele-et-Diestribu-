#define MAX 20
#define MIN 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int tailleTableau()
{
    int taille;
    srand(time(NULL));
    //recuperer la taille de la matrice à generer
    taille = (rand() % (MAX - MIN + 1) + MIN);
    printf("%d\n", taille);
    return taille;
}

int *genererVecteur(int tailleVecteur)
{
    srand(time(NULL));
    //declarer le vecteur
    int *v;
    //declarer l'indice à la valeur 1
    int indiceValAUN = 0;
    //allocation dynamique de la memoire pour le vecteur
    v = (int *)malloc(tailleVecteur * sizeof(int));
    //verifier que l'allocationa reussi et remplir le vecteur
    if (v == NULL)
    {
        printf("Allocation echouée");
        exit(0);
    }
    else
    {
        indiceValAUN = rand() % tailleVecteur;
        v[indiceValAUN] = 1;
        for (int i = 0; i < tailleVecteur; i++)
        {
            if (i != indiceValAUN)
            {
                v[i] = 0;
            }
        }
    }

    for (int j = 0; j < tailleVecteur; j++)
    {
        printf("%d, ", v[j]);
    }
    printf("\n***************\n");
    return v;
    //free(v);
}

int **genererMatrice(int tailleMatrice)
{
    //allocation dynamique de la memoire pour la matrice
    int **A = (int **)malloc(tailleMatrice * sizeof(int *));
    //verifier que l'allocationa reussi et remplir la matrice
    if (A == NULL)
    {
        printf("Allocation echouée");
        exit(0);
    }
    else
    {
        for (int i = 0; i < tailleMatrice; i++)
        {
            A[i] = (int *)malloc(tailleMatrice * sizeof(int));
            if (A[i] == NULL)
            {
                fprintf(stderr, "erreur d'espace memoire");
                exit(0);
            }
        }
    }

    //construire la matrice
    for (int i = 0; i < tailleMatrice; i++)
    {
        for (int j = 0; j < tailleMatrice; j++)
        {
            A[i][j] = (rand() % MAX);
        }
    }

    // afficher la matrice
    for (int i = 0; i < tailleMatrice; i++)
    {
        for (int j = 0; j < tailleMatrice; j++)
        {
            {
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
    }
    return A;
    //free(A);
}

int **genererMatriceIdentite(int tailleMatrice)
{
    //allocation dynamique de la memoire pour la matrice
    int **I = (int **)malloc(tailleMatrice * sizeof(int *));
    if (I == NULL)
    {
        fprintf(stderr, "erreur d'espace memoire");
        exit(0);
    }

    //allocation dynamique de la memoire pour la  seconde dimension
    for (int i = 0; i < tailleMatrice; i++)
    {
        I[i] = (int *)malloc(tailleMatrice * sizeof(int));
        if (I[i] == NULL)
        {
            fprintf(stderr, "erreur d'espace memoire");
            exit(0);
        }
    }

    //construire la matrice
    for (int j = 0; j < tailleMatrice; j++)
    {
        for (int k = 0; k < tailleMatrice; k++)
        {
            if (j == k)
            {
                I[j][k] = 1;
            }
            else
            {
                I[j][k] = 0;
            }
        }
    }

    // afficher la matrice
    for (int r = 0; r < tailleMatrice; r++)
    {
        for (int c = 0; c < tailleMatrice; c++)
        {
            printf("%d ", I[r][c]);
        }

        printf("\n");
    }

    // désallouer la memoire
    for (int r = 0; r < tailleMatrice; r++)
    {
        free(I[r]);
    }

    return I;
}

int *calculeProduitMatriceVecteur(int **A, int *v)
{
    //le vecteur de sortie
    int *w;
    // recuperer la taille du vectuer
    int tailleVecteur = sizeof(v);
    //allocation dynamique de la taille du vecteur
    w = (int *)malloc(tailleVecteur * sizeof(int));
    if (sizeof(A) == sizeof(v))
    {
        for (int i = 0; i < tailleVecteur; i++)
        {
            for (int j = 0; j < tailleVecteur; j++)
            {
                w[i] = w[i] + (A[i][j] * v[j]);
            }
        }
        return w;
    }
    else
    {
        printf("tailles de vecteur et matrice differentes");
        exit(0);
    }
}

int **calculerASigmaI(int **A, int **I, int sigma)
{
    int size_I = sizeof(I);
    for (int i = 0; i < size_I; i++)
    {
        for (int j = 0; j < size_I; j++)
        {
            I[i][j] = I[i][j] * sigma;
            A[i][j] = A[i][j] + I[i][j];
        }
    }
    return A;
}

int **calculeTranspose(int **A)
{
    int tmp = 0;
    //allocation dynamique de la memoire pour la matrice
    int **B = (int **)malloc(sizeof(A) + 1 * sizeof(int *));
    if (B == NULL)
    {
        fprintf(stderr, "erreur d'espace memoire");
        exit(0);
    }

    //allocation dynamique de la memoire pour la  seconde dimension
    for (int i = 0; i < sizeof(A) + 1; i++)
    {
        B[i] = (int *)malloc(sizeof(A) + 1 * sizeof(int));
        if (B[i] == NULL)
        {
            fprintf(stderr, "erreur d'espace memoire");
            exit(0);
        }
    }
    if (sizeof(A) <= 0)
    {
        fprintf(stderr, "Matrice vide");
        exit(0);
    }
    else
    {
        for (int i = 0; i < sizeof(A); i++)
        {
            for (int j = 0; j < sizeof(A); j++)
            {
                if (i != j)
                {
                    B[i][j] = A[j][i];
                }
            }
        }
    }

    // afficher la transposé de la matrice
    for (int r = 0; r < sizeof(B) + 1; r++)
    {
        for (int c = 0; c < sizeof(B) + 1; c++)
        {
            printf("%d ", B[r][c]);
        }

        printf("\n");
    }
}

int calculeNormeVecteur(int *v)
{
    int n, resultat;
    for (int i = 0; i < sizeof(v); i++)
    {
        n += v[i] * v[i];
        resultat = sqrt(n);
    }
    if (resultat == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//calculer l'argument maximale d'un vecteur
int calculeArgMAx(int *v, int size_V)
{
    int max = -1;
    for (int r = 0; r < size_V; r++)
    {
        if (v[r] > max)
        {
            max = v[r];
        }
    }
    return max;
}