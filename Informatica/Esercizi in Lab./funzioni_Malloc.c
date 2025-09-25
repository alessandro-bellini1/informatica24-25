/*CREAREUN ARRAY DINAMICO CHIEDENDO ALL'UTENTE LA SUA DIMENSIONE
IL PROGRAMMA DEVE PREVEDERE LESEGUENTI FUNZIONI
1. CREAL'ARRAY
2. INSERISCE GLI ELEMENTI NELL'ARRAY
3. STAMPA DEI VALORI
4. ESCI*/
#include <stdio.h>
#include <stdlib.h>

int* crea_array(int _dim);
int* inserisci_elementi(int _dim);
int stampa_elementi(int *array, int _dim);
int libera_memoria(int **array);

int main(){
    int *array = NULL; //puntatore al vettore dinamico
    int dim;

    do{
        printf("Inserisci la dimensione dell'array (maggiore di 0): \n");
        scanf("%d", &dim);
    } while (dim <= 0);


    array = crea_array(dim);
    array = inserisci_elementi(dim);
    stampa_elementi(array, dim);
    libera_memoria(&array);

    return 0;
}

int* crea_array(int _dim){
    int *_array = NULL;
    _array = (int *)malloc(_dim * sizeof(int));
    if(_array == NULL){
        printf("Errore nell'allocazione della memoria\n");
        exit(1);
    }
    return _array;
}

int* inserisci_elementi(int _dim){
    int *_array = NULL;
    _array = crea_array(_dim);
    for(int i = 0; i < _dim; i++){
        printf("Inserisci l'elemento %d: \n", i+1);
        scanf("%d", &_array[i]);
    }
    return _array;
}

int stampa_elementi(int *array, int _dim){
    printf("Gli elementi dell'array sono: \n");
    for(int i = 0; i < _dim; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

int libera_memoria(int **array){
    free(*array);
    *array = NULL;
    return 0;
}


