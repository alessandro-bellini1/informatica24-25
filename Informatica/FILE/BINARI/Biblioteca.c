/*CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO;
TUTTO VIENE GESTITO DA FILE BINARI*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;

void aggiungiLibro(){
        FILE *fp;
        Libro libro;
    
        fp = fopen("biblioteca.bin", "ab");
        if(fp == NULL){
            printf("Errore nell'apertura del file.\n");
            return;
        }
        printf("Inserisci autore: ");
        scanf("%s", libro.autore);
        printf("Inserisci titolo: ");
        scanf("%s", libro.titolo);
        printf("Inserisci ISBN: ");
        scanf("%s", libro.ISBN);
        printf("Inserisci anno: ");
        scanf("%d", &libro.anno);
        fwrite(&libro, sizeof(Libro), 1, fp);
        fclose(fp);
}

void cercaLibro(){
        FILE *fp;
        Libro libro;
        char ISBN[20];
        int trovato = 0;
    
        fp = fopen("biblioteca.bin", "rb");
        if(fp == NULL){
            printf("Errore nell'apertura del file.\n");
            return;
        }
        printf("Inserisci ISBN da cercare: ");
        scanf("%s", ISBN);
    
        while(fread(&libro, sizeof(Libro), 1, fp)){
            if(strcmp(libro.ISBN, ISBN) == 0){
                printf("|Libro trovato|\n");
                printf("-Autore: %s\n", libro.autore);
                printf("-Titolo: %s\n", libro.titolo);
                printf("-ISBN: %s\n", libro.ISBN);
                printf("-Anno: %d\n", libro.anno);
                printf("-------------------------\n");
                trovato = 1;
                break;
            }
        }
        if(!trovato){
            printf("Libro non trovato.\n");
        }
        fclose(fp);
}

void cancellaLibro(){
        FILE *fp, *temp;
        Libro libro;
        char ISBN[20];
        int trovato = 0;
    
        fp = fopen("biblioteca.bin", "rb");
        if(fp == NULL){
            printf("Errore nell'apertura del file.\n");
            return;
        }
        temp = fopen("temp.bin", "wb");
        if(temp == NULL){
            printf("Errore nell'apertura del file temporaneo.\n");
            fclose(fp);
            return;
        }
        printf("Inserisci ISBN da cancellare: ");
        scanf("%s", ISBN);
    
        while(fread(&libro, sizeof(Libro), 1, fp)){
            if(strcmp(libro.ISBN, ISBN) == 0){
                printf("|Libro cancellato|\n");
                printf("-Autore: %s\n", libro.autore);
                printf("-Titolo: %s\n", libro.titolo);
                printf("-ISBN: %s\n", libro.ISBN);
                printf("-Anno: %d\n", libro.anno);
                printf("-------------------------\n");
                trovato = 1;
            } else {
                fwrite(&libro, sizeof(Libro), 1, temp);
            }
        }
        if(!trovato){
            printf("Libro non trovato.\n");
        }
        fclose(fp);
        fclose(temp);
        remove("biblioteca.bin");
        rename("temp.bin", "biblioteca.bin");
}

void modificaISBN(){
        FILE *fp;
        Libro libro;
        char ISBN[20];
        int trovato = 0;
    
        fp = fopen("biblioteca.bin", "r+b");
        if(fp == NULL){
            printf("Errore nell'apertura del file.\n");
            return;
        }
        printf("Inserisci ISBN da modificare: ");
        scanf("%s", ISBN);
    
        while(fread(&libro, sizeof(Libro), 1, fp)){
            if(strcmp(libro.ISBN, ISBN) == 0){
                printf("|Libro trovato|\n");
                printf("Inserisci nuovo ISBN: ");
                scanf("%s", libro.ISBN);
                fseek(fp, -sizeof(Libro), SEEK_CUR);
                fwrite(&libro, sizeof(Libro), 1, fp);
                printf("|ISBN modificato|\n");
                printf("-------------------------\n");
                trovato = 1;
                break;
            }
        }
        if(!trovato){
            printf("Libro non trovato.\n");
        }
        fclose(fp);
}

void separaLibri(){
        FILE *fp, *prima2000, *dopo2000;
        Libro libro;
    
        fp = fopen("biblioteca.bin", "rb");
        if(fp == NULL){
            printf("Errore nell'apertura del file.\n");
            return;
        }
        prima2000 = fopen("prima2000.bin", "wb");
        dopo2000 = fopen("dopo2000.bin", "wb");
        if(prima2000 == NULL || dopo2000 == NULL){
            printf("Errore nell'apertura dei file di separazione.\n");
            fclose(fp);
            return;
        }
    
        while(fread(&libro, sizeof(Libro), 1, fp)){
            if(libro.anno < 2000){
                fwrite(&libro, sizeof(Libro), 1, prima2000);
            } else {
                fwrite(&libro, sizeof(Libro), 1, dopo2000);
            }
        }
        fclose(fp);
        fclose(prima2000);
        fclose(dopo2000);
        printf("|Libri separati in prima2000.bin e dopo2000.bin|\n");

        prima2000 = fopen("prima2000.bin", "rb");
        dopo2000 = fopen("dopo2000.bin", "rb");

        printf("\n|Libri prima del 2000|\n");
        while(fread(&libro, sizeof(Libro), 1, prima2000)){
            printf("-Autore: %s\n", libro.autore);
            printf("-Titolo: %s\n", libro.titolo);
            printf("-ISBN: %s\n", libro.ISBN);
            printf("-Anno: %d\n\n", libro.anno);
        }printf("-------------------------\n");
        printf("\n|Libri dopo il 2000|\n");
        while(fread(&libro, sizeof(Libro), 1, dopo2000)){
            printf("-Autore: %s\n", libro.autore);
            printf("-Titolo: %s\n", libro.titolo);
            printf("-ISBN: %s\n", libro.ISBN);
            printf("-Anno: %d\n\n", libro.anno);
        }printf("-------------------------\n");

}

int main(){
        int scelta;
    
        do{
                printf("\n--- Gestione Biblioteca ---\n");
                printf("1. Aggiungi libro\n");
                printf("2. Cerca libro\n");
                printf("3. Cancella libro\n");
                printf("4. Modifica ISBN\n");
                printf("5. Separa libri\n");
                printf("0. Esci\n");
                printf("Scegli un'opzione: ");
                scanf("%d", &scelta);
    
                switch(scelta){
                    case 1:
                            aggiungiLibro();
                            break;
                    case 2:
                            cercaLibro();
                            break;
                    case 3:
                            cancellaLibro();
                            break;
                    case 4:
                            modificaISBN();
                            break;
                    case 5:
                            separaLibri();
                            break;
                    case 0:
                            printf("Uscita dal programma.\n");
                            break;
                    default:
                            printf("Opzione non valida.\n");
                }
        } while(scelta != 0);
    
        return 0;
}