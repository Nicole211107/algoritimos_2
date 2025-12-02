#include <stdio.h>

int main(){

    float n[10];
    int i;
    for(i = 0; i < 10; i++){
        printf("endereco %d: %p\n", i, (void*)&n[i]);
    }

    return 0;
}
