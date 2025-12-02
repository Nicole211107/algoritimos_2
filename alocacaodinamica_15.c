#include <stdio.h>
#include <stdlib.h>

int* multiplicar(int *a, int *b, int n){
    int *c;
    int c1;
    if(n <= 0){
        return 0;
    }
    c = (int*) malloc(n * sizeof(int));
    for(c1 = 0; c1 < n; c1++){
        c[c1] = a[c1] * b[c1];
    }

    return c;
}

int main(){
    int n, c;
    int *a, *b, *d;
    printf("tamanho dos vetores: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    b = (int*) malloc(n * sizeof(int));
    for(c = 0; c < n; c++){
        printf("A[%d]: ", c);
        scanf("%d", &a[c]);
    }

    for(c = 0; c < n; c++){
        printf("B[%d]: ", c);
        scanf("%d", &b[c]);
    }

    d = multiplicar(a, b, n);
    printf("Vetor resultante:\n");
    for(c = 0; c < n; c++){
        printf("%d ", d[c]);
    }
    printf("\n");

    return 0;
}
