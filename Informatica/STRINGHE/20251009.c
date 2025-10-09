/* Stringe con malloc */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* stringa;

int main(){
    stringa buffer; //puntatore alla stringa 
    int dim; //dimensione della stringa

    printf("Quanti caratteri vuoi inserire? ");
    scanf("%d", &dim);

    //alloco lo spazio in memoria
    buffer = (stringa) malloc((dim + 1) * sizeof(char)); //+1 per il carattere di terminazione
    if(buffer == NULL){
        printf("Errore di allocazione della memoria\n");
        return 1;
    }
    printf("Inserisci la stringa: ");
    scanf(" "); //consumo il carattere di newline rimasto nel buffer
    fgets(buffer, dim + 1, stdin); //leggo al massimo dim caratteri

    printf("La stringa inserita e': %s\n", buffer);

    free(buffer); //libero la memoria allocata
}








