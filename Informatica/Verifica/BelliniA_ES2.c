/*INSERIRE UNA SERIE DI VALORI FIN QUANDO LA LORO SOMMA NON SUPERA
200, CALCOLARNE LA MEDIA E IL NUMERO DI VALORI INSERITI.*/
#include <stdio.h>
int main(){

    int valore1, valore2, valore3, valore4, somma;
    float media;
    printf("inserire il primo valore\nscelta: ");
    scanf("%d",&valore1);
    if(valore1>200)
    printf("il primo valore supera 200");
    else{
        printf("inserire il secondo valore\nscelta: ");
        scanf("%d",&valore2);
        somma=valore1+valore2;
        media=somma/2;
        if(somma>200)
        printf("i primi due valori sommati superano 200 e la loro media è: %.2f", media);
        else{
            printf("inserire il terzo valore\nscelta: ");
            scanf("%d",&valore3);
            somma=valore1+valore2+valore3;
            media=somma/3;
            if(somma>200)
            printf("i primi 3 valori sommati superano 200 e la loro media è: %.2f", media);
            else{
                printf("inserire il quarto valore\nscelta: ");
                scanf("%d",&valore4);
                somma=valore1+valore2+valore3+valore4;
                media=somma/4;
                if(somma>200)
                printf("i primi 4 valori sommati superano 200 e la loro media è: %.2f", media);
                else
                printf("i 4 valori sommati non superano 200");
            }
        }
    }
}