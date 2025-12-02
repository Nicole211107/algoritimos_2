#include <stdio.h>

void imprimir(int *a, int n){
    int *p = a;
    int c = 0;
    while(c < n){
        printf("%d ", *p);
        p++;
        c++;
    }
}

int main(){
    int v[5];
    int n = 5;
    int c = 0;
    printf("Informe os valores:\n");
    int *p = v;
    while(c < n){
        scanf("%d", p);
        p++;
        c++;
    }

    printf("Valores do vetor: ");
    imprimir(v, n);

    return 0;
}
