#include <stdio.h>

float calcula(float x, int z){
    float a;
    a = 1;

    int i;
    for (i = 0; i < z; i++){
        a = a * x;
    }

    return a;
}

int main(){
    float x;
    int z;

    scanf("%f", &x);
    scanf("%d", &z);

    float resultado;
    resultado = calcula(x,z);
    printf("resultado%f", resultado);
}