#include <stdio.h>
int idadeparadias (int anos, int meses, int dias)
{
    printf("insira sua idade em anos, meses e dias: \n");
    scanf("%d", &anos);
    scanf("%d", &meses);
    scanf("%d", &dias);
    int total = (anos * 365) + (meses * 30) + dias;
    printf("sua idade total em dias e igual a: %d dias\n", total);
    return total;
}

int main (void)
{
    int anos, meses, dias;
    idadeparadias (anos, meses, dias);
}
