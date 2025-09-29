/*
SCRIVERE UN PROGRAMMA IN C CHE:
1. ALLOCHI DINAMICAMENTE UN ARRAY INIZIALE DI N NUMERI
2. INSERISCI DEI VALORI
3. STAMPA ARRAY
4. CALCOLI LA SOMMA DEGLI ELEMENTI MULTIPLI DI 3
5. CREIAMO UN NUOVO ARRAY CONTENENTE SOLO VALORI DISPARI
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, sum = 0, dispConto = 0;
    int *array, *dispArray;

    // 1. Allocazione dinamica dell'array
    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);
    array = (int *)malloc(n * sizeof(int));
    
    if (array == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return 1;
    }

    // 2. Inserimento dei valori
    for (i = 0; i < n; i++) {
        printf("Inserisci il valore %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // 3. Stampa dell'array
    printf("Array inserito: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 4. Calcolo della somma degli elementi multipli di 3
    for (i = 0; i < n; i++) {
        if (array[i] % 3 == 0) {
            sum += array[i];
        }
    }
    printf("Somma degli elementi multipli di 3: %d\n", sum);

    // 5. Creazione di un nuovo array contenente solo valori dispari usando realloc
    dispArray = NULL;
    for (i = 0; i < n; i++) {
        if (array[i] % 2 != 0) {
            dispArray = (int *)realloc(dispArray, (dispConto + 1) * sizeof(int));
            if (dispArray == NULL) {
                printf("Errore di allocazione della memoria per l'array dispari.\n");
                free(array);
                return 1;
            }
            dispArray[dispConto++] = array[i];
        }
    }

    // Stampa dell'array dispari
    printf("Array dei valori dispari: ");
    for (i = 0; i < dispConto; i++) {
        printf("%d ", dispArray[i]);
    }
    printf("\n");

    // Liberazione della memoria
    free(array);
    free(dispArray);
    return 0;
}