#include <stdio.h>
#include <stdlib.h>

int** criarMatriz(int n){
    int **a;
    int n1, c;
    if(n <= 0){
        return 0;
    }

    a = (int**) malloc(n * sizeof(int*));
    for(n1 = 0; n1 < n; n1++){
        a[n1] = (int*) malloc(n * sizeof(int));
    }

    for(n1 = 0; n1 < n; n1++){
        for(c = 0; c < n; c++){
            if(n1 == c){
                a[n1][c] = 1;
            } else {
                a[n1][c] = 0;
            }
        }
    }

    return a;
}

int main(){
    int n, n1, c;
    int **a;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    a = criarMatriz(n);
    if(a == 0){
        printf("Tamanho invalido.\n");
        return 0;
    }

    printf("Matriz criada:\n");
    for(n1 = 0; n1 < n; n1++){
        for(c = 0; c < n; c++){
            printf("%d ", a[n1][c]);
        }
        printf("\n");
    }

    return 0;
}
