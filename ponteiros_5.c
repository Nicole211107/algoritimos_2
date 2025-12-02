#include <stdio.h>

int main() {
    int a[5];
    int *c = a;
    int n;
    for(n = 0; n < 5; n++) {
        printf("manda o numero ai: ");
        scanf("%d", c + n);
    }

    printf("\n-- dobro dos numeros --\n");
    for(n = 0; n < 5; n++) {
        printf("%d\n", *(c + n) * 2);
    }

    return 0;
}
