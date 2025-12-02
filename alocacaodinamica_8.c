#include <stdio.h>
#include <stdlib.h>

int* criar(int n){
    int *v;
    if(n <= 0){
        return 0;
    }

    v = (int*) malloc(n * sizeof(int));
    if(v == NULL){
        return 0;
    }

    return v;
}

int main(){
    int n;
    int *v;
    printf("Informe o valor de n: ");
    scanf("%d", &n);
    v = criar(n);
    if(v == 0){
        printf("Valor invalido ou memoria insuficiente.\n");
        return 0;
    }

    printf("Vetor criado com sucesso.\n");

    return 0;
}
