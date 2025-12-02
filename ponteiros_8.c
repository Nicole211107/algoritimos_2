#include <stdio.h>

void preencher(int *a, int c, int n){
    int *p = a;
    int k = 0;
    while(k < n){
        *p = c;
        p++;
        k++;
    }
}

int main(){
    int v[5];
    int a;
    int n = 5;
    printf("Informe o valor: ");
    scanf("%d", &a);
    preencher(v, a, n);
    printf("Vetor preenchido: ");
    int *p = v;
    int c = 0;
    while(c < n){
        printf("%d ", *p);
        p++;
        c++;
    }

    return 0;
}
