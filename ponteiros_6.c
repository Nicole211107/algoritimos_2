#include <stdio.h>

int main() {
    int a[5];
    int *c = a;
    int n;
    for(n = 0; n < 5; n++) {
        printf("Informe um número: ");
        scanf("%d", c + n);
    }

    for(n = 0; n < 5; n++) {
        if(*(c + n) % 2 == 0) {
            printf("Endereço do valor par encontrado: %p\n", (c + n));
        }
    }

    return 0;
}
