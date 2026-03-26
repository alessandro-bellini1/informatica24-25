/* Esempio di apertura file in append */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char frase[100];
    char scelta;

    printf("Vuoi svuotare il file? (s/n): ");
    scanf("%c", &scelta);
    while (getchar() != '\n');
    if(scelta=='s' || scelta=='S'){
        // Crea un file vuoto (o sovrascrivi se esiste già)
        f = fopen("dati.txt", "w");
        if (f == NULL) {
            perror("Errore nella creazione del file");
            exit(0);
        }
        fclose(f);
    }

    // Apri il file in modalità append
    f = fopen("dati.txt", "a");
    if (f == NULL) {
        perror("Errore nell'apertura del file");
        exit(0);
    }
    do{
        printf("Inserisci una riga da aggiungere al file: ");
        fgets(frase, sizeof(frase), stdin);
        fputs(frase, f);

        printf("Vuoi inserire un'altra riga? (s/n): ");
        scanf("%c", &scelta);
        // Pulisci il buffer di input
        while (getchar() != '\n');
    }while(scelta=='s' || scelta=='S');

    fclose(f);
    printf("Dati aggiunti al file con successo.\n");

    return 0;
}


