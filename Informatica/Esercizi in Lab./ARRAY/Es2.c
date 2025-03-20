/*Caricato un vettore con valori random
calcolare la media dei valori*/

#include <stdio.h>
#include "libreria.c"
#define DIM 10

int main(){
    int vettore[DIM]={0};
    int MAX=100, MIN=1;

    riempiVettoreCasuale(vettore, DIM, MIN, MAX);
    stampaVettori(vettore,DIM, '\t');
    calcolaMedia(vettore, DIM);

}
