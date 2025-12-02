#include <stdio.h>
#include <stdlib.h>

int** criar(int n){
    int **a;
    if(n <= 0){
        return 0;
    }

    a = (int**) malloc(n * sizeof(int*));
    for(n1 = 0; n1 < n; n1++){
        a[n1] = (int*) malloc(n * sizeof(int));
    }

    for(n1 = 0; n1 < n; n1++){
        for(c = 0; c < n; c++){
            if(c == n1){
                a[n1][c] = 0;
            } else if(c > n1){
                a[n1][c] = 1;
            } else {
                a[n1][c] = -1;
            }
        }
    }

    return a;
}

int main(){
    int n, n1, c;
    int **a;
    printf("tamanho da matriz: ");
    scanf("%d", &n);
    a = criar(n);
    if(a == 0){
        printf("tamanho invalido\n");
        return 0;
    }

    for(n1 = 0; n1 < n; n1++){
        for(c = 0; c < n; c++){
            printf("%d ", a[n1][c]);
        }
        printf("\n");
    }

    return 0;
}
