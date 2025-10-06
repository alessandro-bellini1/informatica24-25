/*Scrivi un programma in C che:
1. chiede all'utente quanti numeri interi vuole inserire;
2. alloca dinamicamente un array di quella dimensione con malloc();
3. permette all'utente di inserire i numeri nell'array;
4. chiede all'utente se vuole aumentare la dimensione dell'array;
   - se si richiede la nuova dimensione e usa realloc() per ridimensionare l'array;
   - permette quindi di inserire i nuovi valori negli spazi aggiunti;
5. infine, stampa tutti i numeri nell'array.
*/

#include <stdio.h>
#include <stdlib.h>

int* creaArr(int n){
    int *_array = (int *)malloc(n * sizeof(int));
    if (_array == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return NULL;
    }
    return _array;
}

int* inserisci_numeri(int *_array, int inizio, int fine){
    for (int i = inizio; i < fine; i++){
        printf("Numero %d: ", i + 1);
        scanf("%d", &_array[i]);
    }
    return _array;
}


int* aumenta_array(int *_array, int *n){
    int nuova_n;
    char scelta;
    printf("Vuoi aumentare la dimensione dell'array? (s/n): ");
    scanf(" %c", &scelta);

    if (scelta == 's' || scelta == 'S'){
        printf("Inserisci la nuova dimensione dell'array: ");
        scanf("%d", &nuova_n);

        int *temp = (int *)realloc(_array, (nuova_n) * sizeof(int));
        if (temp == NULL) {
            printf("Errore di riallocazione della memoria.\n");
            free(_array);
            return NULL;
        }
        _array = temp;

        printf("Inserisci i nuovi numeri interi:\n");
        inserisci_numeri(_array, *n, nuova_n);
        *n = nuova_n;
    }
    return _array;
}

void stampa_array(int *array, int n){
    printf("I numeri nell'array sono:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int n, nuova_n;
    int *array=NULL;

    // Passo 1: Chiedi all'utente quanti numeri inserire
    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    array = creaArr(n);

    // Passo 3: Inserisci i numeri
    array = inserisci_numeri(array, 0, n);

    // Passo 4: Chiedi se aumentare la dimensione dell'array tramite funzione
    array = aumenta_array(array, &n);

    // Passo 5: Stampa tutti i numeri
    stampa_array(array, n);
    stampa_array(array, n);

    free(array);
    return 0;
}