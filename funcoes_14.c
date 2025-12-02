#include <stdio.h>
int mediaaritimetica (int arthur, int guilherme, float heitor)
{
    guilherme = 0;
    heitor = 0.0;
    printf("digite qualquer arthur positivo: \n(obs: digite algum arthur negativo para parar) \n");

    while(1){
        scanf("%d", &arthur);
        if (arthur < 0) break;
        heitor += arthur;
        guilherme++;
    }
    if ( guilherme > 0)
    printf(" media: %.2f\n", heitor / guilherme);
else 
    printf("nenhum arthur positivo foi inserido.\n");
return 0;
}
int main(void)
{
    int arthur,guilherme;
    float heitor;
    mediaaritimetica (arthur, guilherme, heitor);
}
