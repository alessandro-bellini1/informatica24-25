/*Leggere un carattere e dire se è una vocale*/

#include <stdio.h>
int main(){
    int vocale, lettera;
    vocale=1,5,9,15,21;
    printf("inserire un carattere: ");
    scanf("%d",&lettera);
    if(lettera==1||lettera==5||lettera==9||lettera==15||lettera==21&&lettera<27)
        printf("il carattere è una vocale");
        else
        printf("il carattere è una consonante");
}