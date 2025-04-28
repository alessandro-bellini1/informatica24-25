/*Creiamo un menù di richieste
1) caricare un array con solo valori pari;
2) stampare l'array;
3) ordina l'array tramite la tecnica del bubble sort;
*/

#include <stdio.h>
#include "libreria.c"
#define dim 5

int main(){
    int vet[dim];
    int scelta;
    do{
        printf("1) carica un array con solo valori pari\n");
        printf("2) stampa l'array\n");
        printf("3) ordina l'array tramite la tecnica del bubble sort\n");
        printf("4) esci\n");
        printf("scelta: ");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
                caricaVettori(vet, dim);
                break;
            case 2:
                stampaVettori(vet, dim, '\t');
                break;
            case 3:
                bubbleSort(vet, dim);
                break;
            case 4:
                printf("uscita dal programma...\n");
                break;
            default:
                printf("scelta non valida\n");
        }
    }while(scelta!=4);
    return 0;

}