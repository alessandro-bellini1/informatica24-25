/*CREAREUN ARRAY DINAMICO CHIEDENDO ALL'UTENTE LA SUA DIMENSIONE
IL PROGRAMMA DEVE PREVEDERE LESEGUENTI FUNZIONI
1. CREAL'ARRAY
2. INSERISCE GLI ELEMENTI NELL'ARRAY
3. STAMPA DEI VALORI
4. ESCI*/
#include <stdio.h>
#include <stdlib.h>

int* crea_array(int _dim); // funzione per creare un array dinamico
void inserisci_elementi(int *_array, int _dim); // funzione per inserire elementi nell'array
int stampa_elementi(int *array, int _dim); // funzione per stampare gli elementi dell'array
int libera_memoria(int **array); // funzione per liberare la memoria allocata

int main(){
    int *array = NULL; // puntatore al vettore dinamico
    int dim; // variabile per la dimensione dell'array

    do{
        printf("Inserisci la dimensione dell'array (maggiore di 0): \n"); // richiesta dimensione
        scanf("%d", &dim); // lettura dimensione
    } while (dim <= 0); // controllo che sia maggiore di 0

    array = crea_array(dim); // allocazione memoria per array
    inserisci_elementi(array, dim); // inserimento elementi nell'array
    stampa_elementi(array, dim); // stampa degli elementi
    libera_memoria(&array); // liberazione memoria allocata

    return 0; // termine programma
}

int* crea_array(int _dim){
    int *_array = NULL; // dichiarazione puntatore array
    _array = (int *)malloc(_dim * sizeof(int)); // allocazione memoria dinamica
    if(_array == NULL){ // controllo allocazione
        printf("Errore nell'allocazione della memoria\n"); // messaggio errore
        exit(1); // uscita dal programma
    }
    return _array;
}

void inserisci_elementi(int *_array, int _dim){
    for(int i = 0; i < _dim; i++){ // ciclo per inserimento elementi
        printf("Inserisci l'elemento %d: \n", i+1); // richiesta elemento
        scanf("%d", &_array[i]); // lettura elemento
    }
}

int stampa_elementi(int *array, int _dim){
    printf("Gli elementi dell'array sono: \n");
    for(int i = 0; i < _dim; i++){ // ciclo per stampa elementi
        printf("%d ", array[i]); // stampa elemento
    }
    printf("\n");
    return 0;
}

int libera_memoria(int **array){
    free(*array); // liberazione memoria
    *array = NULL; // azzeramento puntatore
    return 0;
}


