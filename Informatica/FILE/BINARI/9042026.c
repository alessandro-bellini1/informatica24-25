/*Creare una rubrica che gestisca la memorizzazione dei
contatti e ne visualizzi l'elenco*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char cognome[20];
    char telefono[15];
} Contatto;

void AggiungiContatto(){
    Contatto c; 
    printf("Inserisci nome: ");
    scanf("%s", c.nome);
    printf("Inserisci cognome: ");
    scanf("%s", c.cognome);
    printf("Inserisci numero di telefono: ");
    scanf("%s", c.telefono);
    FILE *fp = fopen("rubrica.bin", "ab");
    if(fp == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    fwrite(&c, sizeof(Contatto), 1, fp);
    fclose(fp);
}

void VisualizzaRubrica(){
    FILE *fp;
    Contatto c;

    fp = fopen("rubrica.bin", "rb");
    if(fp == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }

    printf("\n--- Rubrica ---\n");
    while(fread(&c, sizeof(Contatto), 1, fp) != 0){
        printf("Nome: %s. Cognome: %s. Telefono: %s\n", c.nome, c.cognome, c.telefono);
    }

    fclose(fp);
}

int main(){
    int scelta;

    do{
        printf("\n--- Menù Rubrica ---\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza rubrica\n");
        printf("0. Esci\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                AggiungiContatto();
                break;
            case 2:
                VisualizzaRubrica();
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Opzione non valida. Riprova.\n");
        }

    }while(scelta != 0);
    
    return 0;
}
        