/*Calcolare quanti e quali numeri primi sono presenti in un ampio intervallo di valori.
Definizione di numero primo: un numero si dice primo se è divisibile solo per 1 e per se stesso.*/
#include <stdio.h>
int main(){
    int num, NP=0;
    printf("inserisci un valore\nscelta: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        for(int j=1; j<=i; j++){
            if(j%i==0&&j%1==i){
                NP=j;
                printf("%d",NP);
                NP=0;
            }
        }
    }


}