#include <stdio.h>

void arthurjosenicole (float a, float j, float n){

    printf(" digite o valor em segundos: \n");
    scanf("%f", &n);

    j = 0;
    a = 0;

    while (n >= 60)
    {
        n = n - 60;
        j++;

    }

    while (j >= 60)
    {
        j = j - 60;
        a++;
    
    }

    printf(" o valor em horas, minutos e segundos e: %f %f %f", a, j, n);

    }

    int main(void){
        float a, j, n;

        arthurjosenicole(a,j,n);

        return (0);
    }