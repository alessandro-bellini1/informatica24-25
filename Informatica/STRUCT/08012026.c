/*Classe di studenti
    Cognome, Nome, classe, matricola.
    poi ogni studente dotato di matricola, abbiano le informazioni
    riguardante gli esami e il livello raggiunto.
    1) ricercare lo studente con più certificazioni;
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char Cognome[20];
    char Nome[20];
    char classe[3];
    int matricola; //1000-9999
    int n_cert; //numero di certificazioni conseguite
} studente;



typedef struct {
    int matricola;
    struct esame{
        char corso[30];
        int livello; //(1-3)
    }esame[5];
} certificazioni;



int main(){
    studente* studente = malloc(3 * sizeof(studente));
    certificazioni* cert = malloc(3 * sizeof(certificazioni));
    //inseriamo i dati degli studenti
    strcpy(studente[0].Cognome, "Rossi");
    strcpy(studente[0].Nome, "Roberto");
    strcpy(studente[0].classe, "4I");
    studente[0].matricola = 123;
    studente[0].n_cert = 0;

    strcpy(studente[1].Cognome, "Verdi");
    strcpy(studente[1].Nome, "Carlo");
    strcpy(studente[1].classe, "3A");
    studente[1].matricola = 456;
    studente[1].n_cert = 0;

    strcpy(studente[2].Cognome, "Gialli");
    strcpy(studente[2].Nome, "Sofia");
    strcpy(studente[2].classe, "5B");
    studente[2].matricola = 789;
    studente[2].n_cert = 0;

    //inseriamo i dati delle certificazioni
    cert[0].matricola = 123;
    strcpy(cert[0].esame.corso, "Inglese");
    cert[0].esame.livello = 2;

    cert[1].matricola = 456;
    strcpy(cert[1].esame.corso, "Spagnolo");
    cert[1].esame.livello = 1;
    
    cert[2].matricola = 789;
    strcpy(cert[2].esame.corso, "Francese");
    cert[2].esame.livello = 3;
    strcpy(cert[2].esame.corso, "Tedesco");
    cert[2].esame.livello = 2;

    //visualizzaziùone dati degli studenti
    printf("\n===|LISTA STUDENTI|===\n");
    for(int i=0; i<3; i++){
        printf("Cognome: %s\n", studente[i].Cognome);
        printf("Nome: %s\n", studente[i].Nome);
        printf("Classe: %s\n", studente[i].classe);
        printf("Matricola: %d\n", studente[i].matricola);
        printf("Numero certificazioni: %d\n", studente[i].n_cert);
        printf("----------------------\n");
    }

    //visualizzare le informazioni riguardo le certificazioni
    printf("\n===|CERTIFICAZIONI STUDENTI|===\n");
    for(int i=0; i<3; i++){
        
        

    free(studente);
    free(cert);
    
    return 0;
}