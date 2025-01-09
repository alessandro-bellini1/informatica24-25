/*Scrivi un programma che ricerca i primi tre numeri perfetti e li visualizza.
numero è perfetto quando la somma dei suoi divisori escluso se stesso è uguale al numero:
esempio n=6 div=1,2,3 somma=1+2+3=6
6  -  28  -  496
*/
#include <stdio.h>
int main(){
int somma=0;
    for(int i=1; i<500; i++){
        for(int j=1; j<i; j++){
            if(i%j==0)
            somma+=j;
        }
        if(i==somma)
        printf("%d  -  ",somma);
        somma=0;
    }
}