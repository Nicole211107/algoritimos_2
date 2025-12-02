#include <stdio.h>
#include <math.h>
 
 struct nicole{
    float x;
    float y;
 };

 int main(){
    struct nicole ponto1;
    struct nicole ponto2;

    scanf("%f",&ponto1.x);
    scanf("%f",&ponto1.y);

    scanf("%f",&ponto2.x);
    scanf("%f",&ponto2.y);

float distanciax;

distanciax = sqrt(pow(ponto2.x - ponto1.x,2) + pow(ponto2.y - ponto1.y,2));

printf("distancia dos pontos%f", distanciax);
 }
 
