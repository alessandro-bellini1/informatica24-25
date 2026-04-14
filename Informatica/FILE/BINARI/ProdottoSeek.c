/*Creata una struct prodotto con nome, ID e prezzo
Scrivere su file binario una serie di prodotti.
modificare il prezzo di un prodotto dato il suo ID*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int ID;
    float prezzo;
} Prodotto;

void aggiungiProdotto(){
    FILE *fp = fopen("prodotti.dat", "ab");
    if(fp == NULL){
        printf("Errore apertura file!\n");
        return;
    }
    int numProdotti;
    printf("Quanti prodotti vuoi aggiungere? ");
    scanf("%d", &numProdotti);
    getchar();
    for(int i = 0; i < numProdotti; i++){
        Prodotto p;
        printf("Prodotto %d:\n", i + 1);
        printf("Inserisci nome prodotto: ");
        scanf(" %[^\n]", p.nome);
        getchar();
        printf("Inserisci ID prodotto: ");
        scanf("%d", &p.ID);
        getchar();
        printf("Inserisci prezzo prodotto: ");
        scanf("%f", &p.prezzo);
        getchar();

        fwrite(&p, sizeof(Prodotto), 1, fp);
    }
    fclose(fp);
    printf("Prodotti aggiunti!\n");
}

void modificaPrezzo(){
    FILE *fp = fopen("prodotti.dat", "r+b");
    if(fp == NULL){
        printf("Errore apertura file!\n");
        return;
    }

    int idRicercato;
    printf("Inserisci ID prodotto da modificare: ");
    scanf("%d", &idRicercato);
    getchar();

    Prodotto p;
    int trovato = 0;

    while(fread(&p, sizeof(Prodotto), 1, fp) == 1){
        if(p.ID == idRicercato){
            printf("Prodotto trovato: %s, Prezzo attuale: %.2f\n", p.nome, p.prezzo);
            printf("Inserisci nuovo prezzo: ");
            scanf("%f", &p.prezzo);
            getchar();

            fseek(fp, -sizeof(Prodotto), SEEK_CUR); // torna indietro alla posizione del prodotto
            fwrite(&p, sizeof(Prodotto), 1, fp); // sovrascrive il prodotto con il nuovo prezzo
            printf("Prezzo aggiornato!\n");
            trovato = 1;
            break;
        }
    }

    if(!trovato){
        printf("Prodotto con ID %d non trovato.\n", idRicercato);
    }

    fclose(fp);
}

void visualizzaProdotti(){
    FILE *fp = fopen("prodotti.dat", "rb");
    if(fp == NULL){
        printf("Nessun prodotto disponibile!\n");
        return;
    }

    Prodotto p;
    printf("\n--- Prodotti ---\n");
    while(fread(&p, sizeof(Prodotto), 1, fp) == 1){
        printf("ID: %d, Nome: %s, Prezzo: %.2f\n", p.ID, p.nome, p.prezzo);
    }
    fclose(fp);
    printf("----------------\n");
}

int main(){
    int scelta;

    do{
        printf("\nMenu:\n");
        printf("1. Aggiungi prodotto\n");
        printf("2. Modifica prezzo prodotto\n");
        printf("3. Visualizza prodotti\n");
        printf("0. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta){
            case 1:
                aggiungiProdotto();
                break;
            case 2:
                modificaPrezzo();
                break;
            case 3:
                visualizzaProdotti();
                break;
            case 0:
                printf("Uscita...\n");
                FILE *fp = fopen("prodotti.dat", "wb"); // apre in modalità scrittura per svuotare il file
                if(fp != NULL){
                    printf("File prodotti svuotato!\n");
                    fclose(fp);
                } else {
                    printf("Errore apertura file!\n");
                }
                break;
            default:
                printf("Opzione non valida!\n");
        }
    } while(scelta != 0);

    return 0;
}

