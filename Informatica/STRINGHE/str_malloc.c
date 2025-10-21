/*data una stringa contare il numero delle vocali.*/
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <ctype.h>      

typedef char* Stringa;  

// Funzione che rimuove il carattere newline dalla fine della stringa
void compatta(Stringa buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){    // Controlla se l'ultimo carattere è un newline
        buffer[len-1] = '\0';            // Sostituisce il newline con terminatore
        len--;                           // Riduce la lunghezza della stringa
    }
}

int conta_vocali(Stringa frase){
    int cnt = 0;                                   
    for(int i = 0; frase[i] != '\0'; i++){         
        char c = tolower(frase[i]);                 // Converte il carattere in minuscolo
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){  // Verifica se è una vocale
            cnt++;                                 
        }
    }
    return cnt;                                    
}

int main(){
    char buffer[200];                              // Buffer temporaneo per l'input
    Stringa frase;                                 // Puntatore per la stringa dinamica

    printf("Inserisci una frase: ");              
    fgets(buffer, sizeof(buffer), stdin);          // Legge l'input dell'utente
    int len = strlen(buffer);                      // Calcola la lunghezza della stringa
    compatta(buffer, len);                         // Rimuove il newline finale
    frase = (Stringa)malloc((len + 1) * sizeof(char)); // Alloca memoria per la stringa
    if (frase == NULL) {                          // Verifica se l'allocazione è riuscita
        printf("Errore di allocazione!\n");
        return 1;
    }
    strcpy(frase, buffer);                         // Copia il buffer nella memoria allocata

    printf("il numero delle vocali e': %d\n", conta_vocali(frase));  // Stampa il risultato
    free(frase);                                   // Libera la memoria allocata
    return 0;
}

