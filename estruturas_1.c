#include <stdio.h>
#include <string.h>

int main()
{
    struct dados
    {
        char nome [100];
        int idade;
        char endereco [500];
    };
    struct dados dados1;
    strcpy (dados1.nome, "Nicole Secorun");
    dados1.idade = 17;
    strcpy (dados1.endereco, "bem longe");

    printf("nome: %s, idade:%d, endereco: %s", dados1.nome, dados1.idade, dados1.endereco);
    return 0;


}
