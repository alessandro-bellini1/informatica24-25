/*Scrivere un programma che inverta ogni riga contenuta 
nel file righe.txt e riporti il risultato sullo scherzo. 
Per esempio la riga "PROVA DI STAMPA"  diventa 
"APMATS ID AVORP"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void InvertiRiga(char *str){
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    //mostra riga
    
}

void InserisciRiga(FILE *fp){
    char str[100];
    printf("Inserisci una riga da aggiungere al file: ");
    fgets(str, sizeof(str), stdin);
    fp = fopen("righe.txt", "a");
    if (fp == NULL){
        printf("Errore nell'apertura del file\n");
        return;
    }
    fprintf(fp, "%s", str);
    fclose(fp);
}

int main(){
    int scelta;
    FILE *fp;
    char str[100];

    do{
        printf("MENU'\n");
        printf("1. Inserisci riga nel file\n");
        printf("2. Inverti righe del file\n");
        printf("3. Esci\n");
        
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        getchar();
        switch (scelta){
            case 1:
            InserisciRiga(fp);
            break;
            case 2:
                InvertiRiga(str);
                printf("\n");
            
            break;
            case 3:
            printf("Uscita dal programma\n");
            break;
            default:
            printf("Scelta non valida\n");
        }
        
            
    }while(scelta != 3);

    return 0;
}
