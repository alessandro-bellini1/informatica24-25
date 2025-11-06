/*Scrivere un programma in linguaggio C che calcoli e visualizzi il codice fiscale (senza il carattere di controllo finale)
chiedendo all’utente di inserire nome, cognome, data di nascita nel formato GG/MM/AAAA, sesso (M o F).
Sarà necessario verificare la correttezza degli input, quindi nome e cognome devono essere composti solo da lettere;
la data deve essere composta solo da numeri (oltre agli eventuali /, si può scegliere se far inserire un valore della data alla volta o tutta la data con il separatore /);
il sesso può avere solo la lettera M o F. Per il controllo di nome, cognome e data, si suggerisce di leggere l’input carattere per carattere usando getchar().
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libstring.c"
typedef char* Stringa;

int validazioneNome(Stringa nome){
    Bool valido = true;
    for(int i=0; i<strlen(nome)-1; i++){ //-1 per escludere il carattere di newline
        if((nome[i] < 'A' || nome[i] > 'Z') && (nome[i] < 'a' || nome[i] > 'z')){
            printf("Nome non valido. Riprova.\n");
            return false; // Non valido
        }
    }
    return true; // Valido
}

int validazioneCognome(Stringa cognome){
    Bool valido = true;
    for(int i=0; i<strlen(cognome)-1; i++){ //-1 per escludere il carattere di newline
        if((cognome[i] < 'A' || cognome[i] > 'Z') && (cognome[i] < 'a' || cognome[i] > 'z')){
            printf("Cognome non valido. Riprova.\n");
            return false; // Non valido
        }
    }
    return true; // Valido
}

void letteraMese(Stringa mese){
    if (strcmp(mese, "01") == 0) mese[0] = 'A';
    else if (strcmp(mese, "02") == 0) mese[0] = 'B';
    else if (strcmp(mese, "03") == 0) mese[0] = 'C';
    else if (strcmp(mese, "04") == 0) mese[0] = 'D';
    else if (strcmp(mese, "05") == 0) mese[0] = 'E';
    else if (strcmp(mese, "06") == 0) mese[0] = 'H';
    else if (strcmp(mese, "07") == 0) mese[0] = 'L';
    else if (strcmp(mese, "08") == 0) mese[0] = 'M';
    else if (strcmp(mese, "09") == 0) mese[0] = 'P';
    else if (strcmp(mese, "10") == 0) mese[0] = 'R';
    else if (strcmp(mese, "11") == 0) mese[0] = 'S';
    else if (strcmp(mese, "12") == 0) mese[0] = 'T';
}


int validazioneData(Stringa data){
    Bool valido = true;
    for(int i=0; i<strlen(data)-1; i++){ //-1 per escludere il carattere di newline
        if((data[i] < '0' || data[i] > '9') && data[i] != '/'){
            printf("Data non valida. Riprova.\n");
            return false; // Non valido
        }
    }
    return true; // Valido
}

void PrimeConsonantiCognome(Stringa cognome, Stringa risultato){
    int count = 0;
    for(int i=0; i<strlen(cognome) && count<3; i++){
        if((cognome[i] >= 'A' && cognome[i] <= 'Z') || (cognome[i] >= 'a' && cognome[i] <= 'z')){
            if(cognome[i]!='A' && cognome[i]!='E' && cognome[i]!='I' && cognome[i]!='O' && cognome[i]!='U' &&
               cognome[i]!='a' && cognome[i]!='e' && cognome[i]!='i' && cognome[i]!='o' && cognome[i]!='u'){
                risultato[count] = cognome[i];
                count++;
            }
        }
    }
    if(count<3){
        //aggiunge la vocale del cognome se le consonanti sono meno di 3
        for(int i=0; i<strlen(cognome) && count<3; i++){
            if((cognome[i] >= 'A' && cognome[i] <= 'Z') || (cognome[i] >= 'a' && cognome[i] <= 'z')){
                if(cognome[i]=='A' || cognome[i]=='E' || cognome[i]=='I' || cognome[i]=='O' || cognome[i]=='U' ||
                   cognome[i]=='a' || cognome[i]=='e' || cognome[i]=='i' || cognome[i]=='o' || cognome[i]=='u'){
                    risultato[count] = cognome[i];
                    count++;
                }   
            }
        }
    }
    risultato[3] = '\0';
}


void PrimeConsonantiNome(Stringa nome, Stringa risultato){
    int count = 0;
    for(int i=0; i<strlen(nome) && count<4; i++){
        if((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z')){
            if(nome[i]!='A' && nome[i]!='E' && nome[i]!='I' && nome[i]!='O' && nome[i]!='U' &&
               nome[i]!='a' && nome[i]!='e' && nome[i]!='i' && nome[i]!='o' && nome[i]!='u'){
                risultato[count] = nome[i];
                count++;
            }
        }
    }
    if(count<3){
        //aggiunge la vocale del nome se le consonanti sono meno di 3
        for(int i=0; i<strlen(nome) && count<3; i++){
            if((nome[i] >= 'A' && nome[i] <= 'Z') || (nome[i] >= 'a' && nome[i] <= 'z')){
                if(nome[i]=='A' || nome[i]=='E' || nome[i]=='I' || nome[i]=='O' || nome[i]=='U' ||
                   nome[i]=='a' || nome[i]=='e' || nome[i]=='i' || nome[i]=='o' || nome[i]=='u'){
                    risultato[count] = nome[i];
                    count++;
                }   
            }
        }
    }else if(count>3){
        //se ci sono piu' di 3 consonanti prende la prima, la terza e la quarta
        risultato[0] = risultato[0];
        risultato[1] = risultato[2];
        risultato[2] = risultato[3];
    }

    risultato[3] = '\0';
}

void calcoloGiorno(Stringa codiceFiscale, Stringa data, char sesso){
    Stringa giorno = (char*) malloc(3 * sizeof(char));
    //CONVERTI LA STRINGA  giorno IN INTERO
    int numGiorno = atoi(data);
    if(sesso == 'F'){
        numGiorno += 40;
    }
}

void calcoloCodiceFiscale(Stringa codiceFiscale, Stringa data, char sesso){
    
    Stringa mese = (char*) malloc(3 * sizeof(char));
    strncpy(mese, data + 3, 2);
    mese[2] = '\0';
    
    Stringa anno = (char*) malloc(5 * sizeof(char));
    strncpy(anno, data + 6, 4);
    anno[4] = '\0';

    strncat(codiceFiscale, anno + 2, 2); //ultime due cifre dell'anno
    codiceFiscale[10] = '\0';
    
    letteraMese(mese);
    strcat(codiceFiscale, mese);
    codiceFiscale[11] = '\0';
    if(sesso != 'F'){
    strncat(codiceFiscale, data, 2); //giorno
    codiceFiscale[13] = '\0';
    }else{
    
    }
    calcoloGiorno(codiceFiscale, data, sesso);

    char G186[] = "G186";
    strcat(codiceFiscale, G186); //Codice del comune di Ostiglia

}


int main(){
    Stringa nome = (Stringa) malloc(30 * sizeof(char));
    Stringa cognome = (Stringa) malloc(30 * sizeof(char));
    Stringa data = (Stringa) malloc(11 * sizeof(char)); //GG/MM/AAAA + \0
    char sesso;
    Stringa codiceFiscale = (Stringa) malloc(16 * sizeof(char)); //15 caratteri + \0
    Stringa risultato = (Stringa) malloc(4 * sizeof(char)); //3 caratteri + \0

    // Input e validazione del nome
    do{
    printf("Inserisci il nome: ");
    fgets(nome, 30, stdin);
    }while(validazioneNome(nome)!=true);

    // Input e validazione del cognome
    do{
    printf("Inserisci il cognome: ");
    fgets(cognome, 30, stdin);
    }while(validazioneCognome(cognome)!=true);

    // Input e validazione della data di nascita
    do{
    printf("Inserisci la data di nascita (GG/MM/AAAA): ");
    fgets(data, 11, stdin);
    }while(validazioneData(data)!=true);

    // Input e validazione del sesso
    do{
    printf("Inserisci il sesso (M/F): ");
    scanf(" %c", &sesso);
    }while(sesso != 'M' && sesso != 'F');
    PrimeConsonantiCognome(cognome, risultato);
    strncat(codiceFiscale, risultato, 3);
    //svutamento stringa risultato per riutilizzarla
    risultato[0] = '\0';
    PrimeConsonantiNome(nome, risultato);
    strncat(codiceFiscale, risultato, 3);
    calcoloCodiceFiscale(codiceFiscale, data, sesso);

    printf("Il codice fiscale e': %s\n", codiceFiscale);

    free(nome);
    free(cognome);
    free(data);
    return 0;
}
