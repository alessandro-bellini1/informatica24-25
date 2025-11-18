/*DATA UNA STRINGA TROVARE UNA SOTTOSTRINGA SENZA UTILIZZARE LA LIBRERIA string.h*/
#include <stdio.h>
#include <stdlib.h>
#include "libstring.h"

typedef char* Stringa;

void stringeMaiuscole(Stringa s1, Stringa s2){
    //trasforma le due stringe in maiuscole per facilitare la ricerca
    int i=0;
    while(s1[i]!='\0'){
        if(s1[i]>='a' && s1[i]<='z'){
            s1[i]=s1[i]-32;
        }
        i++;
    }
    i=0;
    while(s2[i]!='\0'){
        if(s2[i]>='a' && s2[i]<='z'){
            s2[i]=s2[i]-32;
        }
        i++;
    }
}

int trovaSottostringa(Stringa s1, Stringa s2){
    Bool Trovato = true;
    int i, j;
    int len1 = 0, len2 = 0;

    // Calcola la lunghezza di s1
    while(s1[len1] != '\0'){
        len1++;
    }

    // Calcola la lunghezza di s2
    while(s2[len2] != '\0'){
        len2++;
    }

    // Cerca s2 in s1
    for(i = 0; i <= len1 - len2; i++){
        for(j = 0; j < len2; j++){
            if(s1[i + j] != s2[j]){
                break;
            }
        }
        if(j == len2){
            return i; // Sottostringa trovata, ritorna l'indice di inizio
        }
    }
    return false; // Sottostringa non trovata
}

int main(){
    Stringa s1 = (Stringa)malloc(100 * sizeof(char));
    Stringa s2 = (Stringa)malloc(100 * sizeof(char));

    printf("Inserisci la stringa principale: ");
    fgets(s1, 100, stdin);
    printf("Inserisci la sottostringa da cercare: ");
    fgets(s2, 100, stdin);
    stringeMaiuscole(s1, s2);
    int index = trovaSottostringa(s1, s2);
    if(index != false){
        printf("Sottostringa trovata dopo l'indice: %d\n", index);
    }else{
        printf("Sottostringa non trovata.\n");
    }

    free(s1);
    free(s2);
    return 0;
}