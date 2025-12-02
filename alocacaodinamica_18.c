#include <stdio.h>
#include <stdlib.h>

int** multiplicarMatriz(int **a, int lA, int cA, int **b, int lB, int cB){
    int **c;
    int n, m, p;
    if(cA != lB){
        return 0;
    }

    c = (int**) malloc(lA * sizeof(int*));
    for(n = 0; n < lA; n++){
        c[n] = (int*) malloc(cB * sizeof(int));
    }

    for(n = 0; n < lA; n++){
        for(m = 0; m < cB; m++){
            c[n][m] = 0;
            for(p = 0; p < cA; p++){
                c[n][m] += a[n][p] * b[p][m];
            }
        }
    }

    return c;
}

int main(){
    int lA, cA, lB, cB;
    int n, m;
    int **a, **b, **c;
    printf("linhas e colunas da matriz A: ");
    scanf("%d %d", &lA, &cA);
    a = (int**) malloc(lA * sizeof(int*));
    for(n = 0; n < lA; n++){
        a[n] = (int*) malloc(cA * sizeof(int));
    }

    for(n = 0; n < lA; n++){
        for(m = 0; m < cA; m++){
            printf("A[%d][%d]: ", n, m);
            scanf("%d", &a[n][m]);
        }
    }

    printf("linhas e colunas da matriz B: ");
    scanf("%d %d", &lB, &cB);
    b = (int**) malloc(lB * sizeof(int*));
    for(n = 0; n < lB; n++){
        b[n] = (int*) malloc(cB * sizeof(int));
    }

    for(n = 0; n < lB; n++){
        for(m = 0; m < cB; m++){
            printf("B[%d][%d]: ", n, m);
            scanf("%d", &b[n][m]);
        }
    }

    c = multiplicarMatriz(a, lA, cA, b, lB, cB);
    if(c == 0){
        printf("multiplicacao impossivel\n");
        return 0;
    }

    for(n = 0; n < lA; n++){
        for(m = 0; m < cB; m++){
            printf("%d ", c[n][m]);
        }
        printf("\n");
    }

    return 0;
}
