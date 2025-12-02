#include <stdio.h>
float triangulo(float lado_a, float lado_b, float lado_c)
{
    printf("digite os valores a,b e c de um triangulo: \n");
    scanf("%f %f %f", &lado_a, &lado_b, &lado_c);
    if(lado_b+lado_c>lado_a && lado_a+lado_c>lado_b &&lado_a+lado_b>lado_c){
        if(lado_a == lado_b && lado_b == lado_c){
            printf("Se trata de um triangulo equilatero \n");
        }
        else 
        if(lado_a == lado_b || lado_a == lado_c || lado_b == lado_c){
            printf("Se trata de um triangulo isoceles \n");
        }
        else{
            printf("Se trata de um triangulo escaleno \n");
        }
    }
    else{
        printf("Não se trata de um triangulo \n");
    }
    return 0;
}
int main(void)
{
    float lado_a, lado_b, lado_c;
    triangulo(lado_a, lado_b, lado_c);
}