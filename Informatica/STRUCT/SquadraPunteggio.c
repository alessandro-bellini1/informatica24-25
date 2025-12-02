/*creare una struct di tipo squadrea,
essa ha un nome un colore e un punteggio e l'allenatore (nome, cognome, titoli), inserire dall'utente 5 squadre e il punteggio associato,
stampa le squadre con punteggio superiore a 100. fai uso delle funzioni*/

#include <stdio.h>
#include <string.h>

#define MAX_SQUADRE 10

typedef struct{
    char nome[50];
    char colore[20];
    int punteggio;
    char allenatore_nome[50];
    char allenatore_cognome[50];
    int allenatore_titoli;
}Squadra;

void inserisciSquadra(Squadra *s) {
    char c;
    printf("Inserisci il nome della squadra: ");
    fgets(s->nome, 50, stdin);
    printf("Inserisci il colore della squadra: ");
    fgets(s->colore, 20, stdin);
    printf("Inserisci il punteggio della squadra: ");
    scanf("%d", &s->punteggio);
    while((c = getchar()) != '\n') {}
    printf("Inserisci il nome dell'allenatore: ");
    fgets(s->allenatore_nome, 50, stdin);
    printf("Inserisci il cognome dell'allenatore: ");
    fgets(s->allenatore_cognome, 50, stdin);
    printf("Inserisci il numero di titoli dell'allenatore: ");
    scanf("%d", &s->allenatore_titoli);
    while((c = getchar()) != '\n') {}
}

void stampaSquadra(Squadra s, int index) {
    printf("\nSquadra %d:\n", index + 1);
    printf("Nome squadra: %s", s.nome);
    printf("Colore squadra: %s", s.colore);
    printf("Punteggio squadra: %d\n", s.punteggio);
    printf("Allenatore: %s %s, Titoli: %d\n", s.allenatore_nome, s.allenatore_cognome, s.allenatore_titoli);
}

void stampaSquadreConPunteggioSuperiore(Squadra squadre[], int n, int soglia) {
    printf("\nSquadre con punteggio superiore a %d:\n", soglia);
    for(int i = 0; i < n; i++) {
        if(squadre[i].punteggio > soglia) {
            printf("Squadra %d:\n Nome: %s Colore: %s Punteggio: %d\n", i+1, squadre[i].nome, squadre[i].colore, squadre[i].punteggio);
            printf(" Allenatore: %s %s, Titoli: %d\n", squadre[i].allenatore_nome, squadre[i].allenatore_cognome, squadre[i].allenatore_titoli);
        }
    }
}

int main() {
    Squadra squadre[MAX_SQUADRE];
    int scelta;
    char c;
    int numSquadre = 0;

    do {
        printf("\n===== TORNEO DI PALLAVOLO =====\n");
        printf("1. Inserisci nuova squadra\n");
        printf("2. Visualizza squadre\n");
        printf("3. Squadre con punteggio superiore a 100\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        while((c = getchar()) != '\n') {}

        switch (scelta) {
            case 1:
                if (numSquadre < MAX_SQUADRE)
                    inserisciSquadra(&squadre[numSquadre++]);
                else
                    printf("Numero massimo di squadre raggiunto!\n");
                break;
            case 2:
                for (int i = 0; i < numSquadre; i++)
                    stampaSquadra(squadre[i], i);
                break;
            case 3:
                stampaSquadreConPunteggioSuperiore(squadre, numSquadre, 100);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 0);
    
    return 0;
}








