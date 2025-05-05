/*Creiamo un menù di richieste
1) caricare un array con solo valori pari;
2) stampare l'array;
3) ordina l'array tramite la tecnica del bubble sort;
*/

#include <stdio.h>
#include "libreria.c"
#include "libreria.h"

#define DIM 5

int main(){
    int vet[DIM];
    int scelta;
    do{
        printf("1) carica un array con solo valori pari\n");
        printf("2) stampa l'array\n");
        printf("3) ordina l'array tramite la tecnica del bubble sort\n");
        printf("4) Trovato il valore minimo e il valore massimo all'interno dell'array scambiare di posizione\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        
        switch(scelta){
            case 1:
                caricaVettori(vet, DIM);
                break;
            case 2:
                stampaVettore(vet, DIM, '\t');
                break;
            case 3:
                caricaBubble(vet, DIM);
                break;
            case 4:
                scambioMinMax(vet, DIM);
                stampaVettore(vet, DIM, '\t');
                break;
            default:
                printf("scelta non valida\n");
        }
    }while(scelta!=4);
    return 0;

}