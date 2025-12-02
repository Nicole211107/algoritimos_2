#include <stdio.h>
void atletas (int idade)
{
    printf("digite a idade do atleta: \n");
    scanf("%d", &idade);
    if(idade >= 5 && idade <= 7)
    {
        printf("infantil A \n");
    }
    else if(idade >= 8 && idade <=10)
    {
        printf("infantil B \n");
    }
    else if(idade >= 11 && idade<= 13)
    {
        printf("juvenil A \n");
    }
    else if(idade >= 14 && idade <= 17)
    {
        printf("juvenil B \n");
    }
    else if(idade >= 18)
    {
        printf("adulto \n");
    }
    else{
        printf("nao e uma idade valida \n");
    }
}
int main(void) {
    int categoria;
    atletas (categoria);
    return(0);
}
