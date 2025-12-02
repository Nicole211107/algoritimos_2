#include <stdio.h>

int main(){
    int a;
    int *b;
    int **c;
    int ***d;
    b = &a;
    c = &b;
    d = &c;
    printf("Informe um valor: ");
    scanf("%d", &a);
    printf("Dobro: %d\n", (*b) * 2);
    printf("Triplo: %d\n", (**c) * 3);
    printf("Quadruplo: %d\n", (***d) * 4);

    return 0;
}
