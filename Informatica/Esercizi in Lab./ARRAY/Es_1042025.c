/*Caricare
da tastiera un vettore di N elementi. Scorrendo il vettore, al primo
zero incontrato stampare la somma di tutti gli elementi considerati e
il loro numero;*/
#include <stdio.h>
#define DIM 6

int main(){
    int vet[DIM]={0};
    int sommaVett=0;

    caricaVettori(vet[], DIM);
    stampaVettori(vet, DIM);
    sommaVettori(vet, DIM, &cnt)
}
void sommaVettori(int vet[], int dim, int *cnt){
    while(vet[i]!=0 && i<dim){
        somma+=vet[i];
        i++;
        *cnt++;
    }
    return somma;
}
