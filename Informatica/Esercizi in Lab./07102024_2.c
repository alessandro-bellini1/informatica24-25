/*STABILIRE SE UN NUMERO E' DISPARI
    CONTROLLANDO L'ULTIMA CIFRA MENO SIGNIFICATIVA*/
#include <stdio.h>

int main(){
    int num, cifra;
    num=0;
    cifra=0;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    cifra=num%10;
    if(cifra%2==0)
        printf("il numero %d è pari", num);
        else
            printf("il numero %d è dispari", num);

}