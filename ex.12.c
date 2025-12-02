#include <stdio.h>
int ordemcrescente (int gutto, int higor, int nicole)
{
    printf("digite os 3 valores: \n");
    scanf("%d", &gutto);
    scanf("%d", &higor);
    scanf("%d", &nicole);

    for (int i = 0; i <= gutto , i <= higor , i <= nicole; i++)
    {
        if (i == gutto)
        {
            printf("%d \n", gutto);
        }
        if (i == higor)
        {
            printf("%d \n", higor);
        }
        if (i == nicole)
        {
            printf("%d \n", nicole);
        }
    }
    return 0;
}
int main(void)
{
    int gutto, higor, nicole;

    ordemcrescente(gutto, higor, nicole);
}