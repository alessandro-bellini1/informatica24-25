/* DATI 5 VALORI STAMPARLI */
#include <stdio.h>

int main(){
    int num, cnt=0; //5 variabili

    while(cnt<5){
        printf("Inserire un numero\nscelta: ");
        scanf("%d", &num);
        printf("Il valore inserito è: %d\n", num);
        cnt++;
    }
    printf("Il programma è terminato");
    return 0;
}