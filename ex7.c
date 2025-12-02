#include <stdio.h>

int numero (int num)
{
    int soma = 0;
    int cont;
    for (cont = 1; cont < num; cont++){
        if(num % cont == 0){
            soma += cont;
        }
    }
    if (soma == num)
    {
        printf("Se trata de um numero perfeito \n");
    }else{
        printf("Não se trata de um numero perfeito \n");
    }
}
int main (void)
{
    int num;
    printf("Digite algum numero: \n");
    scanf("%d", &num);
    numero (num);
    return (0);
}