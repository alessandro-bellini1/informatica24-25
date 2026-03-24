/*INSERITE LE INFORMAZIONI DI STUDENTI IN UN FILE DI TESTO, OGNI RIGA CONTIENE LE INFORMAZIONI DI UNO STUDENTE:
NOME - ETA' - MEDIA VOTI SCOLASTICI
DETERMINARE LO STUDENTE CON LA MEDIA SCOLASTICA PIU' ALTA*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int eta;
    float media_voti;
} Studente;

Studente* AggiungiStudente(Studente* studenti, int *n) {
    Studente Nuovostudente;
    printf("Inserisci il nome: ");
    scanf("%s", Nuovostudente.nome);
    printf("Inserisci l'età: ");
    scanf("%d", &Nuovostudente.eta);
    printf("Inserisci la media voti: ");
    scanf("%f", &Nuovostudente.media_voti);
    studenti = (Studente*)realloc(studenti, ((*n) + 1) * sizeof(Studente));
    studenti[*n] = Nuovostudente;
    (*n)++;
    FILE *f = fopen("studenti.txt", "a");
    if (f == NULL) {
        printf("Errore nell'apertura del file.\n");
        exit(1);
    }
    fprintf(f, "Studente %d: %s, Età: %d, Media Voti: %.2f\n", *n, Nuovostudente.nome, Nuovostudente.eta, Nuovostudente.media_voti);
    fclose(f);
    return studenti;
}

void StudenteMigliore(Studente* studenti, int *n) {
    if (*n <= 0) {
        printf("Nessuno studente inserito.\n");
        return;
    }
    Studente migliore = studenti[0];
    for (int i = 1; i < *n; i++) {
        if (studenti[i].media_voti > migliore.media_voti) {
            migliore = studenti[i];
        }
    }
    printf("Lo studente con la media più alta è: %s, Età: %d, Media Voti: %.2f\n", migliore.nome, migliore.eta, migliore.media_voti);
}

int main(){
    FILE *f = fopen("studenti.txt", "w");
    if (f == NULL) {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }
    fclose(f);

    Studente* studenti = malloc(sizeof(Studente));
    if (studenti == NULL) {
        printf("Errore di allocazione.\n");
        return 1;
    }
    int n=0, scelta;
    do{
        printf("MENU': \n");
        printf("1. Aggiungi studente\n");
        printf("2. Trova studente con media più alta\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        
        switch (scelta) {
            case 1:
                studenti = AggiungiStudente(studenti, &n);
                break;
            case 2:
                StudenteMigliore(studenti, &n);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 0);
    free(studenti);
    return 0;
}




