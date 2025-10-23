#include <stdio.h>
#include <stdlib.h>
#include "libstring.c"

void palindroma(Stringa s, int _dim){
    Bool flag = true;
    for(int i = 0; i < _dim / 2; i++){
        if(s[i] = s[_dim - i - 1]){
            flag = false;
            break;
        }
    }
    if(flag)
        printf("La stringa è palindroma\n");
    else
        printf("La stringa non è palindroma\n");

}

int main(){
    Stringa s1 = crea_stringa_dinamica('\n');
    int dim = calcola_lunghezza_stringa(s1);

    palindroma(s1, dim);
}
