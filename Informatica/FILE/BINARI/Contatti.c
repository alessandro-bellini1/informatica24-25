/* Creare una rubrica telefonica utilizzando un file binario
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char telefono[15];
    char sesso; // 'M' o 'F'
} Contatto;

void aggiungiContatto() {
    FILE *fp = fopen("rubrica.dat", "ab"); // append in binario
    if (fp == NULL) {
        printf("Errore apertura file!\n");
        return;
    }

    Contatto c;
    printf("Inserisci nome: ");
    scanf(" %[^\n]", c.nome);
    getchar();
    printf("Inserisci telefono: ");
    scanf(" %[^\n]", c.telefono);
    getchar();
    printf("Inserisci sesso (M/F): ");
    scanf(" %c", &c.sesso);
    getchar();

    fwrite(&c, sizeof(Contatto), 1, fp);
    fclose(fp);

    printf("Contatto aggiunto!\n");
}

void eliminaContatto() {
    char nome[30];
    printf("Inserisci nome del contatto da eliminare: ");
    scanf(" %[^\n]", nome);
    getchar();

    FILE *fp = fopen("rubrica.dat", "rb");
    if (fp == NULL) {
        printf("Rubrica vuota!\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Errore apertura file temporaneo!\n");
        fclose(fp);
        return;
    }

    Contatto c;
    int trovato = 0;
    while (fread(&c, sizeof(Contatto), 1, fp) == 1) {
        if (strcmp(c.nome, nome) != 0) {
            fwrite(&c, sizeof(Contatto), 1, temp);// scrivo solo i contatti che non corrispondono al nome da eliminare
        } else {
            trovato = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("rubrica.dat");
    rename("temp.dat", "rubrica.dat");

    if (trovato) {
        printf("Contatto eliminato!\n");
    } else {
        printf("Contatto non trovato!\n");
    }
}

void separaContatti() {
    FILE *fp = fopen("rubrica.dat", "rb");
    if (fp == NULL) {
        printf("Rubrica vuota!\n");
        return;
    }

    FILE *maschi = fopen("maschi.dat", "wb");
    FILE *femmine = fopen("femmine.dat", "wb");
    if (maschi == NULL || femmine == NULL) {
        printf("Errore apertura file di separazione!\n");
        fclose(fp);
        return;
    }

    Contatto c;
    while (fread(&c, sizeof(Contatto), 1, fp) == 1) {
        if (c.sesso == 'M' || c.sesso == 'm') {
            fwrite(&c, sizeof(Contatto), 1, maschi);
        } else if (c.sesso == 'F' || c.sesso == 'f') {
            fwrite(&c, sizeof(Contatto), 1, femmine);
        }
    }

    fclose(fp);
    fclose(maschi);
    fclose(femmine);

    printf("Contatti separati in maschi.dat e femmine.dat!\n");
}

void visualizzaRubrica() {
    FILE *fp = fopen("rubrica.dat", "rb"); // lettura binaria
    if (fp == NULL) {
        printf("Rubrica vuota!\n");
        return;
    }

    Contatto c;
    printf("\n--- Rubrica ---\n");
    while (fread(&c, sizeof(Contatto), 1, fp) == 1) {
        printf("Nome: %s, Telefono: %s, Sesso: %c\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fp);
    printf("---------------\n");
}

int main() {
    //svuota file all'avvio
    FILE *fp = fopen("rubrica.dat", "wb");
    if (fp != NULL) {
        fclose(fp);
    }
    int scelta;

    do {
        printf("\nMenu Rubrica:\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Elimina contatto\n");
        printf("3. Visualizza rubrica\n");
        printf("4. Separa i contatti in base al sesso\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch(scelta) {
            case 1:
                aggiungiContatto();
                break;
            case 2:
                eliminaContatto();
                break;
            case 3:
                visualizzaRubrica();
                break;
            case 4:
                separaContatti();
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while(scelta != 0);

    return 0;
}