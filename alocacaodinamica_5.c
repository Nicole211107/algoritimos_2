#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("digite um valor pra n: ");
    scanf("%d", &n);
    while (n < 0) {
        printf("n invalido, manda outro: ");
        scanf("%d", &n);
    }

    int *v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("nao deu pra alocar\n");
        return 0;
    }

    for (int c = 0; c < n; c++) {
        printf("valor da posicao %d (>=2): ", c + 1);
        scanf("%d", &v[c]);
        while (v[c] < 2) {
            printf("tem q ser >=2, tenta de novo: ");
            scanf("%d", &v[c]);
        }
    }

    printf("valores guardados:\n");
    for (int c = 0; c < n; c++) {
        printf("%d ", v[c]);
    }

    printf("\n");

    return 0;
}
