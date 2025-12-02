#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int *v;
    printf("digite o tamanho do vetor: ");
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    if (v == NULL) {
        printf("nao deu certo a alocacao\n");
        return 0;
    }

    for (int c = 0; c < n; c++) {
        printf("valor %d: ", c + 1);
        scanf("%d", &v[c]);
    }

    printf("\nos valores que vc digitou foram:\n");
    for (int c = 0; c < n; c++) {
        printf("%d ", v[c]);
    }

    printf("\n");
   
    return 0;
}
