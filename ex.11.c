#include <stdio.h>
void avaliacaoAlunos (float nota)
{
    printf("Informe a nota do aluno : \n");
    scanf("%f", nota);
    if(nota >= 0 && nota <= 4.9)
    {
        printf("conceito D \n");
    }
    else if(nota >= 5 && nota <= 6.9)
    {
        printf("conceito C \n");
    }
    else if (nota >= 7 && nota <= 8.9)
    {
        printf("conceito B \n");
    }
    else if(nota >=9 && nota <= 10)
    {
        printf("conceito A \n");
    }
    else{
        printf("Não se trata de um valor valido \n");
    }
}
int main(void){
    int nota;
    avaliacaoAlunos(nota);
    return(0);
}
