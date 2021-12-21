#include <stdio.h>
#include "header.h"

void main()
{
    int **A = genererMatrice(5);
    printf("********************************\n");
    calculeTranspose(A);
}