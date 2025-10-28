/**PROVARE LA LIBRERIA string.h PER LE SEGUENTI OPERAZIONI
    1. CALCOLO LUNGHEZZA STRINGA
    2. CONTROLLO STRINGHE UGUALI
    3. COPIARE UNA STRINGA
    4. CERCARE UN CARATTERE E COMUNICARE LA FREQUENZA
    5. CONCATENARE DUE STRINGHE
    6. RICERCA DI UNA STRINGA NELL'ALTRA
**/
#include <stdio.h>
#include <string.h>
#define LEN 100
int main(){
    int scelta=0;
    do{
        printf("\n--- MENU ---\n");
        printf("1) CALCOLO LUNGHEZZA STRINGA\n");
        printf("2) CONTROLLO STRINGHE UGUALI\n");
        printf("3) COPIARE UNA STRINGA\n");
        printf("4) CERCARE UN CARATTERE E COMUNICARE LA FREQUENZA\n");
        printf("5) CONCATENARE DUE STRINGHE\n");
        printf("6) RICERCA DI UNA STRINGA NELL'ALTRA\n");
        printf("0) ESCI\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1: {
                char str[LEN];
                int dim;
                printf("Inserisci una stringa: ");
                scanf("%s", str);
                printf("La lunghezza della stringa è: %d\n", dim=strlen(str));
                break;
            }
            case 2: {
                char str1[LEN], str2[LEN];
                printf("Inserisci la prima stringa: ");
                scanf("%s", str1);
                printf("Inserisci la seconda stringa: ");
                scanf("%s", str2);
                if (strcmp(str1, str2) == 0)
                    printf("Le stringhe sono uguali.\n");
                else
                    printf("Le stringhe sono diverse.\n");
                break;
            }
            case 3: {
                char str3[LEN], str4[LEN];
                printf("Inserisci la stringa da copiare: ");
                scanf("%s", str3);
                strcpy(str4, str3);
                printf("La stringa copiata è: %s\n", str4);
                break;
            }
            case 4: {
                char *ptr;
                char c;
                int cnt=0;
                char str5[LEN];
                printf("Inserisci una stringa: ");
                scanf("%s", str5);
                printf("Inserisci il carattere da cercare: ");
                scanf(" %c", &c);
                ptr = str5;
                while((ptr = strchr(ptr, c)) != NULL){
                    cnt++;
                    ptr++; // Avanza il puntatore per cercare ulteriori occorrenze
                }
                printf("Il carattere '%c' appare %d volte nella stringa.\n", c, cnt);
                break;
            }
            case 5: {
                char str1[LEN], str2[LEN];
                printf("Inserisci la prima stringa: ");
                scanf("%s", str1);
                printf("Inserisci la seconda stringa: ");
                scanf("%s", str2);
                strcat(str1, str2);
                printf("La stringa concatenata è: %s\n", str1);
                break;
            }
            case 6: {
                char str1[LEN], str2[LEN];
                printf("Inserisci la stringa principale: ");
                scanf("%s", str1);
                printf("Inserisci la stringa da cercare: ");
                scanf("%s", str2);
                if (strstr(str1, str2) != NULL)
                    printf("La stringa '%s' è stata trovata in '%s'.\n", str2, str1);
                else
                    printf("La stringa '%s' non è stata trovata in '%s'.\n", str2, str1);
                break;
            }
            default:
                printf("Scelta non valida.\n");
        }
    }while(scelta!=0);
    return 0;
}