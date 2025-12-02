#include <stdio.h>
#include <stdlib.h>

int* criaVetor(int N, int c){
    if(N <= 0){
        return NULL;
    }

    int *p = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++){
        p[i] = c;
    }

    return p;
}

int main(){
    int n, c;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Digite o valor para preencher: ");
    scanf("%d", &c);
    int *v = criaVetor(n, c);
        printf("Tamanho invalido.\n");
        return 0;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);

    return 0;
}
