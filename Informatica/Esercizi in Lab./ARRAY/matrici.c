/*Scrivi un programma che permetta all'utente di salvare in una matrice 4 voti per ognuno di 8 studenti diversi. Quindi salva in un vettore la media dei voti di ogni studente e stampala.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define righe 8
#define colonne 4
int main(){
    float voti[righe][colonne];
    float medie[righe];
    float somma=0;
    for(int i=0; i<righe; i++){
        printf("Studente %d: ", i+1);
        for(int j=0; j<colonne; j++){
            printf("Inserisci il voto: ");
            scanf("%f", &voti[i][j]);
        }

    }
    for(int i=0; i<righe; i++){
        printf("studente: %d", i+1);
        for(int j=0; j<colonne; j++){
            printf("voto: %d", voti[i][j]);
        }
    }
    for(int i=0; i<righe; i++){
        somma=0;
        for(int j=0; j<colonne; j++){
            somma+=voti[i][j];
        }medie[i]=somma/colonne;
    }
    for(int i=0; i<righe; i++){
        printf("media studente %d: %f",i+1, medie[i]);
    }

}