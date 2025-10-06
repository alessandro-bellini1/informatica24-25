/*scrivi un programma in C che gestisca un insieme di numeri interi
usando un array dinamico.
il programma deve permettere, tramite menù con switch/case:
1. Aggiungere un numero (espandendo l'array con realloc)
2. Visualizzare tutti i numeri
3. Cercare un numero specifico
4. Ordinare i numeri in ordine crescente
5. Eliminare un numero scelto dall'utente
6. Uscire dal programma
*/

#include <stdio.h>
#include <stdlib.h>

int* creaArr(int dim){
    int *_array = (int *)malloc(dim * sizeof(int));
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

int main(){
    int *array = NULL; //array dinamico
    int dim = 0; //quanti elementi ci sono
    int scelta, n, i, j, trovato;

// Passo 1: Chiedi all'utente quanti numeri inserire
    printf("Quanti numeri interi vuoi inserire? ");
    scanf("%d", &dim);

    do{
        printf("\n--- MENU ---\n");
        printf("1. Aggiungi numero\n");
        printf("2. Visualizza numeri\n");
        printf("3. Cerca numero\n");
        printf("4. Ordina numeri (crescente)\n");
        printf("5. Elimina numero\n");
        printf("6. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1: //Aggiungi
            printf("Inserisci un numero: ");
            scanf("%d", &n);
            array = (int *)realloc(array, (dim + 1) * sizeof(int));
            if(array == NULL){
                printf("Errore di allocazione!\n");
                return 1;
            }
            array[dim] = n;
            dim++;
            printf("Numero aggiunto!\n");

        case 2: //Visualizza
            printf("Numeri attuali:\n");
            for(i = 0; i < dim; i++)
                printf("%d ", array[i]);
            if(dim == 0) printf("(nessun numero)");
            printf("\n");

        case 3: //Cerca
            printf("Numero da cercare: ");
            scanf("%d", &n);
            trovato = 0;
            for(i = 0; i < dim; i++){
                if(array[i] == n){
                    printf("Trovato all'indice %d\n", i);
                    trovato = 1;
                    break;
                }
            }
            if(!trovato)
                printf("Numero non trovato.\n");

        case 4: //Ordina (Bubble Sort)
            for(i = 0; i < dim- 1; i++){
                for(j = 0; j < dim - i - 1; j++){
                    if(array[j] > array[j + 1]){
                        int temp = array[j];
                        array [j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }
            printf("Numeri ordinati in ordine crescente.\n");

        case 5: //Elimina
            printf("Numero da eliminare: ");
            scanf("%d", &n);
            trovato = 0;
            for(i = 0; i < dim; i++){
                if(array[i] == n){
                    for(j = i; j < dim - 1; j++){
                        array[j] = array[j + 1];
                    }
                    dim--;
                    array = (int *)realloc(array, dim * sizeof(int));
                    if(array == NULL && dim > 0){
                        printf("Errore di allocazione!\n");
                        return NULL;
                    }
                    printf("Numero eliminato.\n");
                    trovato = 1;
                    break;
                }
            }
            if(!trovato)
                printf("Numero non trovato.\n");  
            break;
        case 6: //Esci
            printf("Uscita...\n");
            break;
        default:
            printf("Scelta non valida.\n");
        }
    }while(scelta != 6);



