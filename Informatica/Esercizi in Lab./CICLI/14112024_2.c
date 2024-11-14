/* LEGGERE UNA SEQUENZA DI NUMERI, VISUALIZZARLA.
SI TERMINA NON APPENA ARRIVA UNO 0 */

#include <stdio.h>

int main(){
    int num;

    printf("Inserire un numero:\nscelta: ");
    scanf("%d", &num);
    
    while(num|=0){
        printf("Inserire un numero:\nscelta: ");
        scanf("%d", &num);
    }
    printf("Hai inserito uno 0 il programma termina.\n");
    return 0;
}