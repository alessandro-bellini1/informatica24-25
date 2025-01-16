/*Richiesti due numeri da tastiera verifica e comunica se sono numeri Amici/Amicali.
Definizione di numeri Amicali: due numeri si dicono amicali se la somma dei divisori del primo
numero è uguale al secondo numero e viceversa.*/
#include <stdio.h>
int main(){
    int n1, n2, somma=0, somma2=0;
    printf("inserisci un valore al primo numero\nscelta: ");
    scanf("%d", &n1);
    printf("inserisci un valore al secondo numero\nscelta: ");
    scanf("%d", &n2);
    for(int i=1; i<=n1; i++){
        if(n1%i==0)
        somma+=i;
    }
    if(somma==n2)
    printf("la somma dei divisori del primo numero è uguale al secondo numero %d",somma);
    for(int j=1; j<=n2; j++){
        if(n2%j==0)
        somma2+=j;
    }
    if(somma2==n1)
    printf("la somma dei divisori del secondo numero è uguale al primo numero %d",somma2);
}