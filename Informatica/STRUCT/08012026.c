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
} studente;

typedef struct{
    int matricola;
    struct esame{
        char corso[30];
        int livello; //(1-3)
    };
} certificazioni;

void CreaStudente(studente S[]){
    for(int i=0; i<5; i++){
        printf("Inserisci Cognome: ");
        scanf("%s", S[i].Cognome);
        printf("Inserisci Nome: ");
        scanf("%s", S[i].Nome);
        printf("Inserisci Classe: ");
        scanf("%s", S[i].classe);
        S[i].matricola = rand() % 9000 + 1000; //matricola casuale tra 1000 e 9999
    }
}
void AssegnaCertificazioni(studente S[]){
    certificazioni C[5][10]; //massimo 10 certificazioni per studente
    for(int i=0; i<5; i++){
        int numCertificazioni = rand() % 11; //da 0 a 10 certificazioni
        for(int j=0; j<numCertificazioni; j++){
            C[i][j].matricola = S[i].matricola;
            sprintf(C[i][j].corso, "Corso_%d", j+1);
            C[i][j].livello = rand() % 3 + 1; //livello tra 1 e 3
        }
    }
}
void CercaStudenteConPiuCertificazioni(studente S[]){
    certificazioni C[5][10];
    int maxCertificazioni = -1;
    int indiceStudente = -1;
    for(int i=0; i<5; i++){
        int count = 0;
        for(int j=0; j<10; j++){
            if(C[i][j].matricola == S[i].matricola){
                count++;
            }
        }
        if(count > maxCertificazioni){
            maxCertificazioni = count;
            indiceStudente = i;
        }
    }
    if(indiceStudente != -1){
        printf("Lo studente con più certificazioni è %s %s con %d certificazioni.\n", S[indiceStudente].Nome, S[indiceStudente].Cognome, maxCertificazioni);
    } else {
        printf("Nessuno studente ha certificazioni.\n");
    }
}

int main(){
    studente S[5];
    CreaStudente(S);
    AssegnaCertificazioni(S);
    int n;
    while(n!=0){
        printf("Premi 1 per cercare lo studente con più certificazioni, 0 per uscire: ");
        scanf("%d", &n);
        if(n==1){
            CercaStudenteConPiuCertificazioni(S);
        }
    }
    return 0;
}