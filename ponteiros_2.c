#include <stdio.h>

int main(){
    int a;
    int c;
    int *pa;
    int *pc;
    pa = &a;
    pc = &c;
    printf("coloca um valor pra a: \n");
    scanf("%d", &a);
    printf("coloca um valor pra c: \n");
    scanf("%d", &c);
    if(pa > pc){
        printf("o conteudo do maior endereco e: %d\n", *pa);
    } else {
        printf("o conteudo do maior endereco e: %d\n", *pc);
    }

    return 0;
}
