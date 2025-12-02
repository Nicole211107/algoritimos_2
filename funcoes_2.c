#include <stdio.h>
void printartexto(char texto[], int tamanho)
{
    printf("escreva um texto: \n");
    fgets(texto, tamanho, stdin);
    printf("o texto digitado foi: %s\n", texto);
}

int main(void){
    char texto[3000];
    printartexto(texto, sizeof(texto));
    return 0;
}
