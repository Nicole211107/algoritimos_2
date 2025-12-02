#include <stdio.h>
#include <stdlib.h>

int procurar(int **m, int l, int col, int v){
    int n, c;
    for(n = 0; n < l; n++){
        for(c = 0; c < col; c++){
            if(m[n][c] == v){
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int l, col;
    int **m;
    int n, c;
    int v;
    printf("digite quantas linhas: ");
    scanf("%d", &l);
    printf("digite quantas colunas: ");
    scanf("%d", &col);
    m = (int**) malloc(l * sizeof(int*));
    for(n = 0; n < l; n++){
        m[n] = (int*) malloc(col * sizeof(int));
    }

    for(n = 0; n < l; n++){
        for(c = 0; c < col; c++){
            printf("valor [%d][%d]: ", n, c);
            scanf("%d", &m[n][c]);
        }
    }

    printf("digite o valor para procurar: ");
    scanf("%d", &v);
    if(procurar(m, l, col, v) == 1){
        printf("o valor esta na matriz\n");
    } else {
        printf("o valor nao esta na matriz\n");
    }

    return 0;
}
