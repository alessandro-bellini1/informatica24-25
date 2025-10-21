/*eliminare gli spazi da una stringa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Stringa;

Stringa elimina_spazi(Stringa s1, int *dim1){
    int cnt = 0;
    for(int i = 0; i < *dim1; i++){
        if(s1[i] != ' ')
            s1[cnt++] = s1[i];
    }
    s1[cnt] = '\0';
    *dim1 = cnt-1; // Aggiorna la dimensione della stringa
    return s1;
}

void compatta(Stringa buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){    // Controlla se l'ultimo carattere è un newline
        buffer[len-1] = '\0';            // Sostituisce il newline con terminatore
        len--;                           // Riduce la lunghezza della stringa
    }
}

int main(){
    Stringa s1 = (Stringa)malloc(100 * sizeof(char));
    printf("Inserisci una stringa: ");

    fgets(s1, 100, stdin);
    int len = strlen(s1);

    // Rimuovi il carattere di nuova linea se presente
    compatta(s1, len);

    printf("Stringa originale: %s\n", s1);
    s1 = elimina_spazi(s1, &len);
    compatta(s1, strlen(s1));
    printf("Stringa senza spazi: %s\n", s1);
    printf("la dimensione vale: %d\n", len);
    return 0;
}