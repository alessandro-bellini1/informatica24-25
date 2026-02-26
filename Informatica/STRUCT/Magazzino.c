/*DATA LA STRUCT PRODOTTO: - NOME - CODICE - QUANTITà - PREZZO.
ESEGUIRE:
1. INSERIRE PRODOTTO
2. STAMPARE ELENCO PRODOTTI
3. CERCARE UN PRODOTTO PER CODICE
4. CALCOLARE IL VALORE TOTALE DEL MAGAZZINO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int codice;
    int quantita;
    float prezzo;
} Prodotto;

Prodotto InserireProdotto(){
    Prodotto p;
    printf("Inserisci nome prodotto: ");
    scanf("%s", p.nome);
    printf("Inserisci codice prodotto: ");
    scanf("%d", &p.codice);
    printf("Inserisci quantita prodotto: ");
    scanf("%d", &p.quantita);
    printf("Inserisci prezzo prodotto: ");
    scanf("%f", &p.prezzo);
    return p;
}

void VisualizzaProdotti(Prodotto prodotti[], int numProdotti){
    for (int i = 0; i < numProdotti; i++){
        printf("Nome: %s, Codice: %d, Quantità: %d, Prezzo: %.2f\n",
                prodotti[i].nome, prodotti[i].codice, prodotti[i].quantita, prodotti[i].prezzo);
    }
}

void CercaProdotto(Prodotto prodotti[], int numProdotti, int codice){
    for (int i = 0; i < numProdotti; i++){
        if (prodotti[i].codice == codice){
            printf("Nome: %s, Codice: %d, Quantità: %d, Prezzo: %.2f\n",
                    prodotti[i].nome, prodotti[i].codice, prodotti[i].quantita, prodotti[i].prezzo);
            return;
        }
    }
    printf("Prodotto con codice %d non trovato.\n", codice);
}

void CalcolaValoreTotaleMagazzino(Prodotto prodotti[], int numProdotti){
    float totale = 0;
    for (int i = 0; i < numProdotti; i++){
        totale += prodotti[i].quantita * prodotti[i].prezzo;
    }
    printf("Valore totale del magazzino: %.2f\n", totale);
}

int main(){
    Prodotto prodotti[100];
    int numProdotti = 0;
    int scelta;

    do {
        printf("\n===== GESTIONE MAGAZZINO =====\n");
        printf("1. Inserisci nuovo prodotto\n");
        printf("2. Visualizza prodotti\n");
        printf("3. Cerca prodotto per codice\n");
        printf("4. Calcola valore totale magazzino\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                if (numProdotti < 100){
                    prodotti[numProdotti++] = InserireProdotto();
                } else {
                    printf("Limite massimo di prodotti raggiunto.\n");
                }
                break;
            case 2:
                VisualizzaProdotti(prodotti, numProdotti);
                break;
            case 3:
                printf("Inserisci codice prodotto da cercare: ");
                int codice;
                scanf("%d", &codice);
                CercaProdotto(prodotti, numProdotti, codice);
                break;
            case 4:
                CalcolaValoreTotaleMagazzino(prodotti, numProdotti);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida.\n");
        }
    } while (scelta != 0);
    return 0;
}