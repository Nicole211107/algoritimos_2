#include <stdio.h>
#include <stdlib.h>

int* fazer(int n){
    int *v;
    int c;
    v = (int*) malloc(n * sizeof(int));
    if(v == NULL){
        return 0;
    }

    for(c = 0; c < n; c++){
        v[c] = c;
    }

    return v;
}

int main(){
    int n, c;
    int *v;
    printf("Informe o valor de n: ");
    scanf("%d", &n);
    v = fazer(n);
    if(v == 0){
        printf("Nao foi possivel alocar memoria.\n");
        return 0;
    }

    printf("Valores do vetor:\n");
    for(c = 0; c < n; c++){
        printf("%d ", v[c]);
    }

    printf("\n");

    return 0;
}
