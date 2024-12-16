/*Calcolare la somma dei primi N numeri naturali.
Es: 5 1+2+3+4+5
*/
#include <stdio.h>
int main(){
    int N=0, somma=0;
    do{printf("inserisci un numero\nscelta: ");
    scanf("%d",&N);
    }while(N<0);
    for(int i=1; i<=N; i++){
        somma+=i;
        printf("%d+",i);
    }
    printf("\nla somma dei numeri N è: %d\n",somma);
}