/*introduzione agli array*/
#include <stdio.h>
#define MAX 10      //cerca il nome e sostituisce il valore.
int main(){
    int v[MAX];      //int v[10];

    for(int i=0; i<MAX; i++){
        v[i] = 1;
        printf("%d\t", v[i]);
    }

    return 0;
}