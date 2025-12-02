#include <stdio.h>

int main(){

    float m[3][3];
    int n, c;
    for(n = 0; n < 3; n++){
        for(c = 0; c < 3; c++){
            printf("endereco [%d][%d]: %p\n", n, c, (void*)&m[n][c]);
        }
    }

    return 0;
}
