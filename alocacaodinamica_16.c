#include <stdio.h>
#include <stdlib.h>

int* produto(int **a, int *b, int n){
    int *c;
    int n1, c1;
    int soma;
    if(n <= 0){
        return 0;
    }

    c = (int*) malloc(n * sizeof(int));
    for(n1 = 0; n1 < n; n1++){
        soma = 0;
        for(c1 = 0; c1 < n; c1++){
            soma += a[n1][c1] * b[c1];
        }
        c[n1] = soma;
    }

    return c;
}

int main(){
    int n, n1, c1, c;
    int **a;
    int *b, *d;
    printf("tamanho da matriz e do vetor: ");
    scanf("%d", &n);
    a = (int**) malloc(n * sizeof(int*));
    for(n1 = 0; n1 < n; n1++){
        a[n1] = (int*) malloc(n * sizeof(int));
    }

    b = (int*) malloc(n * sizeof(int));
    for(n1 = 0; n1 < n; n1++){
        for(c1 = 0; c1 < n; c1++){
            printf("A[%d][%d]: ", n1, c1);
            scanf("%d", &a[n1][c1]);
        }
    }

    for(c = 0; c < n; c++){
        printf("B[%d]: ", c);
        scanf("%d", &b[c]);
    }

    d = produto(a, b, n);
    printf("Vetor resultante:\n");
    for(c = 0; c < n; c++){
        printf("%d ", d[c]);
    }
    printf("\n");

    return 0;
}
