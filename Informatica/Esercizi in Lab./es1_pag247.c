/*scrivi un  programma che, dati in input n numeri interi e un numero x determini: 
- quanti numeri sono maggiori di x;
- quanti numeri sono minori di x;
- quanti numeri sono uguali a x*/
#include <stdio.h>
int main(){
    int n=0, numero=0, X=0, maggiore=0, minore=0, uguale=0;
    printf("inserisci un valore per quanti numeri dovrai inserire\nscelta: ");
    scanf("%d",&n);
    printf("inserisci un valore per X\nscelta: ");
    scanf("%d",&X);
    for(int i=0; i<n; i++){
        printf("inserisci un valore per il numero\nscelta: ");
        scanf("%d",&numero);
        if(numero>X)
        maggiore++;
        else if(numero<X)
        minore++;
        else if(numero==X)
        uguale++;
    }
    printf("i numeri maggiori ad X sono in totale: %d\ni numeri minori ad X sono in totale: %d\ni numeri uguali ad X sono in totale: %d",maggiore, minore, uguale);
}