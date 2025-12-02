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
        printf("o maior endereco e o de a: %p\n", pa);
    } else {
        printf("o maior endereco e o de c: %p\n", pc);
    }

    return 0;
}
