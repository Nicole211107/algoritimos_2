#include <stdio.h>

int numeropositivo(int a)
{
    printf("digite um valor inteiro: \n");
    scanf("%d", &a);

    if(a >= 0)
    {
        printf("seu numero e positivo. \n"); 
    }
    else{
        printf("seu numero e negativo. \n");
    }
    return a;
}

int main(void){
int a;
numeropositivo(a);
printf("0 \n");
}