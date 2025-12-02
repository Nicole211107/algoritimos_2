#include <stdio.h>
int numeroparimpar (int a)
{
    printf("digite um valor : \n");
    scanf("%d", &a);

    if(a % 2 == 0)
    {
        printf("seu numero e par . \n");
    }
    else{
        printf("seu numero e impar . \n");
    }
    return a;
}
int main(void){
    int a;
    numeroparimpar (a);
    printf("0 \n");
}
