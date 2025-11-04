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
    int numeroMese = 0;
    for(int i=0; i<2; i++){
        numeroMese = mese[i] - '0' + numeroMese * 10; 
    }
    switch(numeroMese){
        case 1: mese[0]='A';
        case 2: mese[0]='B';
        case 3: return 'C';
        case 4: return 'D';
        case 5: return 'E';
        case 6: return 'H';
        case 7: return 'L';
        case 8: return 'M';
        case 9: return 'P';
        case 10: return 'R';
        case 11: return 'S';
        case 12: return 'T';
        default: return '\0'; // Valore di errore
    }
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


void calcoloCodiceFiscale(Stringa codiceFiscale, Stringa nome, Stringa cognome, Stringa data, char sesso){
    strncpy(codiceFiscale, cognome, 3);
    codiceFiscale[3] = '\0';
    strncat(codiceFiscale, nome, 3);
    codiceFiscale[6] = '\0';
    char barra='/';
    strrchr(data, barra); //GG/MM/AAAA
    codiceFiscale[8] = '\0';

    Stringa giorno = (char*) malloc(3 * sizeof(char));
    if(sesso == 'F'){
        giorno[0]+= '4';
        strncpy(giorno, data, 2);
    } else {
        strncpy(giorno, data, 2);
    }
    
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

    strcat(codiceFiscale, giorno);
    codiceFiscale[13] = '\0';

    char G186[] = "G186";
    strcat(codiceFiscale, G186); //Codice del comune di Ostiglia

}


int main(){
    Stringa nome = (Stringa) malloc(30 * sizeof(char));
    Stringa cognome = (Stringa) malloc(30 * sizeof(char));
    Stringa data = (Stringa) malloc(11 * sizeof(char)); //GG/MM/AAAA + \0
    char sesso;
    Stringa codiceFiscale = (Stringa) malloc(16 * sizeof(char)); //15 caratteri + \0

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

    calcoloCodiceFiscale(codiceFiscale, nome, cognome, data, sesso);



    printf("Codice Fiscale calcolato: \n", codiceFiscale);

    free(nome);
    free(cognome);
    free(data);
    return 0;
}
