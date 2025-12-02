/*  esempio di utilizzo di una struct complessa
    facendo accesso ai campi in modalità variabile
    e in modalità puntatore alla struct
*/
#include <stdio.h>
#include <stdlib.h>

// definizione della struct
typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
} Persona;

int main(){
    Persona p1;
    Persona *p2;

    // inseriamo le informazioni in p1
    printf("Inserisci nome: ");
    scanf("%s", p1.nome);
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%19s", p1.cognome);
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &p1.eta);
    fflush(stdin);

    // stampiamo le informazioni di p1
    printf("\nDati di p1:\n");
    printf("Nome: %s\n", p1.nome);
    printf("Cognome: %s\n", p1.cognome);
    printf("Eta': %d\n", p1.eta);

    // ora lavoriamo con il puntatore p2
    p2 = (Persona*) malloc(sizeof(Persona));
    if (p2 == NULL) {
        printf("Errore di allocazione memoria!\n");
        return 1;
    }

    // inseriamo le informazioni in p2
    printf("\nInserisci nome: ");
    scanf("%s", p2->nome);
    fflush(stdin);
    printf("Inserisci cognome: ");
    scanf("%s", p2->cognome);
    fflush(stdin);
    printf("Inserisci eta': ");
    scanf("%d", &p2->eta);
    fflush(stdin);
    
    // stampiamo le informazioni di p2
    printf("\nDati di p2:\n");
    printf("Nome: %s\n", p2->nome);
    printf("Cognome: %s\n", p2->cognome);
    printf("Eta': %d\n", p2->eta);
    free(p2); // liberiamo la memoria allocata
    return 0;
}



