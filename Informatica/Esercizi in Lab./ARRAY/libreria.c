/*
    Sviluppiamo le funzioni
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

void riempiVettoreCasuale(int vet[], int dim, int minimo, int massimo){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        vet[i]=rand()%(massimo-minimo+1)+minimo;
    }
}
void calcolaMedia(int vet[], int dim){
    int Somma=0, Media=0;
    for(int i=0; i<dim; i++){
        Somma+=vet[i];
        
    }
    Media+=Somma/dim;
    printf("la media dei valori casuali è: %d",Media);
}

