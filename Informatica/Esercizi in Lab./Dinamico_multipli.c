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

int* allocArray(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Errore di allocazione della memoria.\n");
        exit(1);
    }
    return arr;
}

void insertValues(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Inserisci il valore %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumMultipli3(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int* creaArrayDispari(int *arr, int n, int *dispCount) {
    int *dispArr = NULL;
    *dispCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            dispArr = (int *)realloc(dispArr, (*dispCount + 1) * sizeof(int));
            if (dispArr == NULL) {
                printf("Errore di allocazione della memoria per l'array dispari.\n");
                exit(1);
            }
            dispArr[(*dispCount)++] = arr[i];
        }
    }
    return dispArr;
}

int main() {
    int n, dispCount, *array, *dispArray;

    printf("Inserisci il numero di elementi: ");
    scanf("%d", &n);

    array = allocArray(n);
    insertValues(array, n);

    printf("Array inserito: ");
    printArray(array, n);

    printf("Somma degli elementi multipli di 3: %d\n", sumMultipli3(array, n));

    dispArray = creaArrayDispari(array, n, &dispCount);

    printf("Array dei valori dispari: ");
    printArray(dispArray, dispCount);

    free(array);
    free(dispArray);
    return 0;
}