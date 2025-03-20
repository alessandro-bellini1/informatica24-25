/*
    Sviluppiamo le funzioni
*/
#include <stdio.h>
#include "libreria.h" //prototipi delle funzioni

void richiediValori(int vet[], int dim){
    int n=0, i=0;

    while(i<dim){
        printf("inbserisci un valore\nscelta: ");
        scanf("%d", &n);
        if(n%2==0){
            vet[i]=n;
            i++;
        }
    }

}
    
void stampaVettori(int vet[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c",vet[i],sep);
    }
}