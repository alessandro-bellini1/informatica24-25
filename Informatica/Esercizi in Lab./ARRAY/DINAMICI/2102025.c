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

int main() {
    int n, new_n, i;
    int *array;

    // Step 1: Ask user for the number of integers
    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &n);

    // Step 2: Allocate memory for the array
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione della memoria.\n");
        return 1;
    }

    // Step 3: Allow user to input numbers
    printf("Inserisci %d numeri interi:\n", n);
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Step 4: Ask if user wants to increase the size of the array
    char choice;
    printf("Vuoi aumentare la dimensione dell'array? (s/n): ");
    scanf(" %c", &choice);

    if (choice == 's' || choice == 'S') {
        printf("Inserisci la nuova dimensione dell'array: ");
        scanf("%d", &new_n);

        // Reallocate memory for the new size
        int *temp = (int *)realloc(array, new_n * sizeof(int));
        if (temp == NULL) {
            printf("Errore di riallocazione della memoria.\n");
            free(array);
            return 1;
        }
        array = temp;

        // Allow user to input new values in the added spaces
        printf("Inserisci i nuovi numeri interi:\n");
        for (i = n; i < new_n; i++) {
            printf("Numero %d: ", i + 1);
            scanf("%d", &array[i]);
        }
        n = new_n; // Update n to the new size
    }

    // Step 5: Print all numbers in the array
    printf("I numeri nell'array sono:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free allocated memory
    free(array);
    return 0;
}