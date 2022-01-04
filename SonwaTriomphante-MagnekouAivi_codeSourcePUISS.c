#define MAX 5
#define MIN 2
#define MAXTHREADS 4
#define MAXTVAL 100

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

int tailleTableau()
{
    int taille;
    srand(time(NULL));
    //recuperer la taille de la matrice à generer
    taille = (rand() % (MAXTVAL - MIN + 1) + MIN);
    return taille;
}

float *genererVecteur(int tailleVecteur)
{
    srand(time(NULL));
    //declarer le vecteur
    float *v;
    //declarer l'indice à la valeur 1
    int indiceValAUN = 0;
    //allocation dynamique de la memoire pour le vecteur
    v = (float*)malloc(tailleVecteur * sizeof(float));
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

    printf("\n***Le vecteur****\n");

    for (int j = 0; j < tailleVecteur; j++)
    {
        printf("%.2f, ", v[j]);
    }
    printf("\n***************\n");
    return v;
    //free(v);
}

//generer un matrice
float **genererMatrice(int tailleMatrice)
{
    //allocation dynamique de la memoire pour la matrice
    float **A = (float **)malloc(tailleMatrice * sizeof(float *));
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
            A[i] = (float *)malloc(tailleMatrice * sizeof(float));
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
            A[i][j] = (rand() % (MAX + 1 - 0) + 0);
        }
    }

    // afficher la matrice
     printf("\n***La matrice****\n");
    for (int i = 0; i < tailleMatrice; i++)
    {
        for (int j = 0; j < tailleMatrice; j++)
        {
            {
                printf("%.2f ", A[i][j]);
            }
        }
        printf("\n");
    }
    return A;
    //free(A);
}


// generer une matrice  d'identité
float **genererMatriceIdentite(int tailleMatrice)
{
    //allocation dynamique de la memoire pour la matrice
    float **I = (float**)malloc(tailleMatrice * sizeof(float *));
    if (I == NULL)
    {
        fprintf(stderr, "erreur d'espace memoire");
        exit(0);
    }

    //allocation dynamique de la memoire pour la  seconde dimension
    for (int i = 0; i < tailleMatrice; i++)
    {
        I[i] = (float*)malloc(tailleMatrice * sizeof(float));
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
            printf("%.2f ", I[r][c]);
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

float *calculeProduitMatriceVecteur(float **A, float *v, int tailleVecteur)
{
    //le vecteur de sortie
    float *w;
    //allocation dynamique de la taille du vecteur
    w = (float *)malloc(tailleVecteur * sizeof(float));

    for (int k = 0; k < tailleVecteur; k++)
    {
       w[k] = 0.00;
    }

    for (int i = 0; i < tailleVecteur; i++)
    {
        for (int j = 0; j < tailleVecteur; j++)
        {
            w[i] =  w[i] + (A[i][j] * v[j]);
        }
    }

    for (int c = 0; c < tailleVecteur; c++)
    {
        printf("%.2f ", w[c]);
    }
     printf("\n");
    return w;
}

//calculer AsigmaI
float **calculerASigmaI(float **A, float **I, int sigma)
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


//calculer la transposé d'une matrice
float **calculeTranspose(float **A, int taille_M)
{
    int tmp = 0;
    //allocation dynamique de la memoire pour la matrice
    float **B = (float **)malloc(taille_M * sizeof(float *));
    if (B == NULL)
    {
        fprintf(stderr, "erreur d'espace memoire");
        exit(0);
    }

    //allocation dynamique de la memoire pour la  seconde dimension
    for (int i = 0; i < taille_M; i++)
    {
        B[i] = (float *)malloc(taille_M* sizeof(float));
        if (B[i] == NULL)
        {
            fprintf(stderr, "erreur d'espace memoire");
            exit(0);
        }
    }
    if (taille_M <= 0)
    {
        fprintf(stderr, "Matrice vide");
        exit(0);
    }
    else
    {
        for (int i = 0; i < taille_M; i++)
        {
            for (int j = 0; j < taille_M; j++)
            {
                if (i != j)
                {
                    B[i][j] = A[j][i];
                }
            }
        }
    }

    // afficher la transposé de la matrice
    for (int r = 0; r < taille_M + 1; r++)
    {
        for (int c = 0; c < taille_M+ 1; c++)
        {
            printf("%.2f ", B[r][c]);
        }

        printf("\n");
    }
}

//calculer la norme du vecteur
int calculeNormeVecteur(float *v, int taille_V)
{
    int n, resultat;
    for (int i = 0; i < taille_V; i++)
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
float calculeArgMAx(float *v, int size_V)
{
    float maxVal = -1.00;
    for (int r = 0; r < size_V; r++)
    {
        if (v[r] > maxVal)
        {
            maxVal = v[r];
        }
    }
    return maxVal;
}

int main()
{
    clock_t debut = clock();
    clock_t fin = clock();
    double temps_exec;
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

        //debut main

        int taille;
        float **A; 
        float *v,*w;
        float alpha, lamba = 1.00;
        float *tableauValPropre = NULL;
        float *vecteurPropre = NULL;
        int compteur, step = 0;
        float norme = 0;
        taille = MAXTVAL;
        printf("\ntaille: %d\n", taille);

        vecteurPropre = malloc(taille * sizeof(float));
        tableauValPropre = malloc(MAXTVAL * sizeof(float));
        
        //initialiser le vecteur a 0
        for (int k = 0; k < taille; k++)
        {
            w[k] = 0.00;
        }

        //initialiser le vecteur a 0
        for (int c = 0; c < taille; c++)
        {
            vecteurPropre[c] = 0.00;
        }
        
        A = genererMatrice(taille);
        v = genererVecteur(taille);
        
        //commncer les tests
        
        debut:
            w = calculeProduitMatriceVecteur(A, v, taille);
            //afficher le vecteur
            printf("\nresultant vector\n");

            //for (int j = 0; j < taille; j++)
            for (int k = 0; k < taille; k++)
            {
                printf("%.2f ", w[k]);
            }

            alpha = calculeArgMAx(w, taille);
            printf("\nalpha : %.2f\n", alpha);

            //extraire le vecteur propre
            for(int i = 0; i < taille;i++)
            {
                vecteurPropre[i] = (1/alpha)* w[i];
            }

            printf("\nvecteur propre\n");
            for (int r = 0; r < taille; r++)
            {
                printf("%.2f, ", vecteurPropre[r]);
            }

            v = vecteurPropre;
            tableauValPropre[step] = alpha;
        if((alpha  - (float)lamba) > 0.01){
            lamba = alpha;
            printf("\n\nvaleur propre %.2f\n\n", lamba);
            step++;
            goto debut;
        }
        float alphaFinal = calculeArgMAx(tableauValPropre, MAXTVAL);
        printf("\n\nLa valeur propre maximale: %.2f", alphaFinal);

        
        //compteur -= 1;
        //faire le doiuble pour garder les vecteurs avec virgule
    temps_exec = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("\ntemps d'exec: %.3f\n", temps_exec);

    return 0;
}