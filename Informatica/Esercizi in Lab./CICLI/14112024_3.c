/* LEGGERE UNA SEQUENZA DI NUMERI, VISUALIZZARLA E DETERMINARE QUANTI
NUMERI SONO STATI INSERITI.
SI TERMINA NON APPENA ARRIVA UNO 0 */

#include <stdio.h>

int main(){
    int num, cntn=0;

    printf("Inserire un numero:\nscelta: ");
    scanf("%d", &num);
    cntn++;
    while(num|=0){
        printf("Inserire un numero:\nscelta: ");
        scanf("%d", &num);
        cntn++;
    }
    printf("Hai inserito uno 0 il programma termina.\nHai inserito %d volte un numero\n", cntn);
    return 0;
}