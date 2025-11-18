/*DATA UNA STRINGA SCRIVERLA ALL'INVERSO*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* Stringa;

void stringaFlip(Stringa s, int len){
    //Invertire la stringa s nella stessa s
    char temp;
    for(int i=0; i<len/2; i++){
        temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
}

int main(){
    int scelta=0;
    do{
        printf("\n--- MENU ---\n");
        printf("1) Flip stringa\n");
        printf("2) Esci\n");
        printf("Scelta: ");
        scanf("%d",&scelta);
        
        switch(scelta){
            case 1:
            Stringa str=malloc(sizeof(char));
            int len=strlen(str);
            if(str==NULL){
                printf("Errore di allocazione \n");
                exit(1);
            }
                printf("Inserisci una stringa: ");
                int c;
                while ((c = getchar()) != '\n'){}
            do{
                scanf("%c",&str[len]);
                len++;
                str = (char *) realloc(str, (len)*sizeof(char));
                if(str==NULL){
                    printf("Errore di riallocazione \n");
                    exit(1);
                }
            }while(str[len-1]!='\n');
            str[len-1] ='\0'; //sostituisco il carattere di nuova linea con il terminatore di stringa
            len--; //aggiorno la lunghezza della stringa
            stringaFlip(str, len);
            printf("Stringa invertita: %s\n", str);
            free(str);
                break;
            case 2:
                printf("Uscita dal programma...\n");
                break;
        }
    }while(scelta!=2);
    return 0;
}

