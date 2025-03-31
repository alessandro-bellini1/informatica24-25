/*dati due vettori , fare lo scambio di valori*/
#include <stdio.h>
#include "libreria.h"
#include "libreria.c"
#define DIM 5
int main(){
    int vettore[DIM];
    int vettore2[DIM];
    riempiVettoreCasuale(vettore, vettore2, DIM,  0, 10);
    scambiaVettori(vettore, vettore2, DIM);
    stampaVettori(vettore, vettore2, DIM, '\t');
}
