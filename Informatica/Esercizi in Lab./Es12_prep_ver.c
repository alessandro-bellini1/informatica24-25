/*Scrivi un programma che visualizzi la somma dei quadrati dei primi 12 numeri
naturali successivi a 8
esempio: somma=9*9+10*10+11*11+12*12....
*/

#include <stdio.h>
int main(){
    int inizio=0,somma=0,quantita=0;
    printf("inserisci il valore iniziale\nscelta: ");
    scanf("%d",&inizio);
    printf("inserisci quanti elementi vuoi considerare\nscleta: ");
    scanf("%d", &quantita);
    for(int i=inizio+1; i<inizio+quantita; i++){
        somma+=i*i;
    }
    printf("lla somma dei %d valori da %d vale: %d",quantita, inizio, somma);
}