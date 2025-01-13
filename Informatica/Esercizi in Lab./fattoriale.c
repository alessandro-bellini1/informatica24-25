/*Scrivi un programma che esegue il calcolo del fattoriale
di un numero num inserito.*/
#include <stdio.h>
int main(){
    int num,fatt=1;
    printf("inserisci un numero\nscelta: ");
    scanf("%d",&num);
    for(int i=1; i<=num; i++)
        fatt*=i;
    printf("il calcolo del fattoriale di %d vale %d", num, fatt);
}