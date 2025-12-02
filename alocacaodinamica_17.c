#include <stdio.h>
#include <stdlib.h>

int* somaColunas(int **a, int n){
    int *b;
    int n1, c;
    int soma;
    if(n <= 0){
        return 0;
    }

    b = (int*) malloc(n * sizeof(int));
    for(c = 0; c < n; c++){
        soma = 0;
        for(n1 = 0; n1 < n; n1++){
            soma += a[n1][c];
        }
        b[c] = soma;
    }

    return b;
}

int main(){
    int n, n1, c;
    int **a;
    int *b;
    printf("tamanho da matriz: ");
    scanf("%d", &n);
    a = (int**) malloc(n * sizeof(int*));
    for(n1 = 0; n1 < n; n1++){
        a[n1] = (int*) malloc(n * sizeof(int));
    }

    for(n1 = 0; n1 < n; n1++){
        for(c = 0; c < n; c++){
            printf("A[%d][%d]: ", n1, c);
            scanf("%d", &a[n1][c]);
        }
    }

    b = somaColunas(a, n);
    printf("Soma das colunas:\n");
    for(c = 0; c < n; c++){
        printf("%d ", b[c]);
    }
    printf("\n");

    return 0;
}
