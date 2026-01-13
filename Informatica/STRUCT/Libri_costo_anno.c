/* Registrare le informazioni di alcuni libri con
    titolo, autore, anno e prezzo
    determinare il libro più costoso  e il libro più vecchio
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LIBRO{
    char titolo[40];
    char autore[30];
    int anno;
    float prezzo;
}LIBRO;

void compatta(char* buffer, int len){

        if(len>0 && buffer[len-1]=='\n'){
            buffer[len-1] = '\0';
            len--;
        }
}

int main(){
    LIBRO *libri;

    int n=3, datato, i_datato, i_costoso;
    float costoso;

    libri = (LIBRO*)malloc(n * sizeof(LIBRO));

    if (libri == NULL){
        printf("Errore di allocazione\n");
        return 1;
    }

    //inseriamo i dati
    strcpy(libri[0].titolo, "L'amore mio noin muore");
    strcpy(libri[0].autore, "Roberto Saviano");
    libri[0].anno = 2025;
    libri[0].prezzo = 19.50;

    strcpy(libri[1].titolo, "Maledetti di Dio");
    strcpy(libri[1].autore, "Sven Assel");
    libri[1].anno = 1953;
    libri[1].prezzo = 13.31;

    strcpy(libri[2].titolo, "Il diritto di contare");
    strcpy(libri[2].autore, "Margot Lee Shetterly");
    libri[2].anno = 2017;
    libri[2].prezzo = 19.50;

    
    n++;
    libri = (LIBRO*)realloc(libri, n * sizeof(LIBRO));
    if (libri == NULL){
        printf("Errore di riallocazione\n");
        return 1;
    }
    strcpy(libri[3].titolo, "Orgoglio e pregiudizio");
    strcpy(libri[3].autore, "Jane Austen");
    libri[3].anno = 1813;
    libri[3].prezzo = 9.99;

   
    //calcolo il libro più datato
    datato = libri[0].anno;
    i_datato = 0;
    for (int i=1; i<n; i++){
        if (libri[i].anno < datato){
            datato = libri[i].anno;
            i_datato = i;
        }
    }
    printf("il libro piu\' datato e\': %s di %s, anno %d\n", libri[i_datato].titolo, libri[i_datato].autore, libri[i_datato].anno);
    
    //calcolo il libro più costoso
    costoso = libri[0].prezzo;
    i_costoso = 0;
    for (int i=1; i<n; i++){
        if (libri[i].prezzo > costoso){
            costoso = libri[i].prezzo;
            i_costoso = i;
        }
    }
    printf("il libro piu\' costoso e\': %s di %s, prezzo %.2f\n", libri[i_costoso].titolo, libri[i_costoso].autore, libri[i_costoso].prezzo);

    //eliminare un libro
    printf("\n===|Eliminazione di un libro|===\n");
    int len;
    char* titolo_elimina = (char*)malloc(40 * sizeof(char));
    if(titolo_elimina == NULL){
        printf("Errore di allocazione\n");
        return 1;
    }
    
    printf("inserisci il titolo del libro da eliminare: ");
    fgets(titolo_elimina, 40, stdin);
    //rimuovo il carattere di newline
    len = strlen(titolo_elimina);
    compatta(titolo_elimina, len);

    int i=0;
    for(i=0; i<n; i++){
        if (!strcmp(libri[i].titolo, titolo_elimina)){
            
            //sposto tutti gli elementi successivi di una posizione indietro
            for (int j=i; j<n-1; j++){
                libri[j] = libri[j+1];
            }
            n--;
            libri = (LIBRO*)realloc(libri, n * sizeof(LIBRO));
            if (libri == NULL){
                printf("Errore di riallocazione\n");
                return 1;
            }
            printf("Libro eliminato con successo.\n");
            break;
        }
    }
    if (i == n){
        printf("Libro non trovato.\n");
    }

     //visualizzazione dei dati
    printf("\n===|Elenco libri|===\n");
    for (int i=0; i<n; i++){
        printf("Libro %d:\n", i+1);
        printf("Titolo: %s\n", libri[i].titolo);
        printf("Autore: %s\n", libri[i].autore);
        printf("Anno: %d\n", libri[i].anno);
        printf("Prezzo: %.2f\n", libri[i].prezzo);
        printf("-------------------\n");
    }
    
    free(libri);
    free(titolo_elimina);

    return 0;
}
