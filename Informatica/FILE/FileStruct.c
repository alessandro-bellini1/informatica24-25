#include <stdio.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
} Persona;

Persona AggiungiPersona(Persona* P){
    if(P == NULL){
        printf("Errore nell'allocazione della memoria\n");
        return *P;
    }
    printf("Inserisci nome: ");
    scanf("%s", P.nome);
    printf("Inserisci cognome: ");
    scanf("%s", P.cognome);
    printf("Inserisci eta: ");
    scanf("%d", &P.eta);
    return P;
}

int main(){
    Persona*P = malloc(sizeof(Persona));
    if(P == NULL){
        printf("Errore nell'allocazione della memoria\n");
        return 1;
    }

    FILE *f = fopen("persona.txt", "w+");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    
    *P = AggiungiPersona(P);
    fprintf(f, "%s %s %d\n", P.nome, P.cognome, P.eta);

    fscanf(f, "%s %s %d", P.nome, P.cognome, &P.eta);
    printf("Dati letti dal file:\n Nome: %s\n Cognome: %s\n Età: %d\n", P.nome, P.cognome, P.eta);
    fclose(f);
    
    return 0;
}