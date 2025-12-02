#include <stdio.h>

struct nicole{
    int dia;
    int mes;
    int ano;
};

int main(){
    struct nicole data1;
    struct nicole data2;
    printf("coloca o dia da primeira data: \n");
    scanf("%d", &data1.dia);
    printf("coloca o mes da primeira data: \n");
    scanf("%d", &data1.mes);
    printf("coloca o ano da primeira data: \n");
    scanf("%d", &data1.ano);
    printf("coloca o dia da segunda data: \n");
    scanf("%d", &data2.dia);
    printf("coloca o mes da segunda data: \n");
    scanf("%d", &data2.mes);
    printf("coloca o ano da segunda data: \n");
    scanf("%d", &data2.ano);
    int dias1 = data1.ano * 365 + data1.mes * 30 + data1.dia;
    int dias2 = data2.ano * 365 + data2.mes * 30 + data2.dia;
int diferenca;
    if(dias1 > dias2){
        diferenca = dias1 - dias2;
    } else {
        diferenca = dias2 - dias1;
    }

    printf("o numero de dias entre as duas datas é: %d\n", diferenca);
    return 0;
}
