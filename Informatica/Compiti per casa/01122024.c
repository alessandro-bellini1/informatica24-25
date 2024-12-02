/*Scrivi un programma che effettua il prodotto tra due numeri utilizzando il metodo delle somme successive 
dopo aver controllato l’input e accettato solo valori maggiori di 0.*/
#include <stdio.h>
int main(){
    int num1, num2, i, somma=0;
    do{
    printf("inserisci un numero\nscelta: ");
    scanf("%d",&num1);
    }while(num1<0);
    do{
    printf("inserisci un'altro numero\nscelta: ");
    scanf("%d",&num2);
    }while(num2<0);
    
    for(i=0;i<num1;i++){
        somma+=num2;
    }
    printf("%d * %d = %d",num1, num2, somma);
    
    return 0;
}