/*Dato numero a più cifre comunicare quale e quante cifre corrispondono alla propria posizione
Esempio: n1=4211 la cifra 1corrisponde alla prima posizione e la cifra 4
corrisponde alla quarta posizione.*/
#include <stdio.h>
int main(){
    int num, cnt=0;
    printf("inserisci un valore\nscelta: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
    if(num%10!=0){
        cnt++;
    }
    }
    printf("%d",cnt);




}