#include <stdio.h>
#include <stdlib.h>

char* inverter(char *s){
    int n = 0;
    int c = 0;
    char *r;
    while(s[n] != '\0'){
        n++;
    }

    r = (char*) malloc((n + 1) * sizeof(char));
    if(r == NULL){
        return 0;
    }

    for(c = 0; c < n; c++){
        r[c] = s[n - 1 - c];
    }

    r[n] = '\0';

    return r;
}

int main(){
    char s[200];
    char *inv;
    printf("digite a string: ");
    scanf("%s", s);
    inv = inverter(s);
    if(inv == 0){
        printf("nao deu pra inverter.\n");
        return 0;
    }

    printf("string invertida: %s\n", inv);

    return 0;
}
