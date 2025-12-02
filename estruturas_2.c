#include <stdio.h>
#include <math.h>
int main()
{
    struct pontos
    {
        float x,y;
    };
    float raiz = 0, soma = 0;
    struct pontos pontos1;

    printf("digite os pontos: \n");

    scanf("%f", &pontos1.x);
    scanf("%f", &pontos1.y);
    
    pontos1.x = pow (pontos1.x,2);
    pontos1.y = pow (pontos1.y,2);

    soma = pontos1.x + pontos1.y;
    raiz = sqrt (soma);
    printf("a distancia dos pontos é de: %.2f \n", raiz);
    
    return(0);
}
