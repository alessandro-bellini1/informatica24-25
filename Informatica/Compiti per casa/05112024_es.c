/*Scrivi un programma in C che permetta di inserire 1 voto di uno studente.
Poi genera casualmente un secondo voto compreso tra 4 e 8.
Quindi permetta di scegliere quale operazione fare tra:
- 1 mostrare la media dei due voti
- 2 mostrare il voto maggiore tra i due
- 3 mostrare il voto minore tra i due.
- 4 mostrare il numero di voti sufficiente tra i due.
Verificare che il voto inserito sia compreso tra 2 e 10.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float voto1, voto2, media;
    int scelta;
    float maggiore, minore;

    // Inizializza il generatore di numeri casuali
    srand(time(NULL));

    // Inserimento del primo voto senza ciclo
    printf("Inserisci il primo voto dello studente (tra 2.0 e 10.0): ");
    scanf("%f", &voto1);

    // Controllo se il voto è valido
    if (voto1 < 2.0 || voto1 > 10.0){
        printf("Errore: il voto deve essere compreso tra 2.0 e 10.0.\n");
    } else{
    // Generazione del secondo voto casuale tra 4.0 e 8.0
    voto2 = ((float)rand() / RAND_MAX) * 4.0 + 4.0;  // Genera un numero tra 4.0 e 8.0
    printf("Il secondo voto generato casualmente e': %.2f\n", voto2);

        // Calcolo dei risultati necessari
        media = (voto1 + voto2) / 2.0;
        maggiore = (voto1 > voto2) ? voto1 : voto2;
        minore = (voto1 < voto2) ? voto1 : voto2;

        // Scelta dell'operazione da eseguire
        printf("Scegli un'operazione da eseguire:\n");
        printf("1 - Mostra la media dei due voti\n");
        printf("2 - Mostra il voto maggiore tra i due\n");
        printf("3 - Mostra il voto minore tra i due\n");
        printf("4 - Mostra i voti sufficienti tra i due\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        // Esegui l'operazione scelta
        switch (scelta) {
            case 1:
                printf("La media dei due voti e': %.2f\n", media);
                break;
            case 2:
                printf("Il voto maggiore tra i due e': %.2f\n", maggiore);
                break;
            case 3:
                printf("Il voto minore tra i due e': %.2f\n", minore);
                break;
            case 4:
                printf("Voti sufficienti tra i due: ");
                if (voto1 >= 6.0) {
                    printf("%.2f ", voto1);
                }
                if (voto2 >= 6.0) {
                    printf("%.2f ", voto2);
                }
                if (voto1 < 6.0 && voto2 < 6.0) {
                    printf("Nessuno dei due voti è sufficiente.");
                }
                printf("\n");
                break;
            default:
                printf("Scelta non valida.\n");
                break;
        }
    
    }   

    return 0;
}
