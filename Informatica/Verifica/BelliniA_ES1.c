/*Esercizio1
CONTARE IL NUMERO DI CIFRE DI CUI SI COMPONE UN NUMERO DATO E
COMUNICARE QUANTE VOLTE COMPARE LA CIFRA DI VALORE K CHIESTA
ALL’UTENTE.
N.B.: accettare valori che vanno da 0 a 9999
ES: 3 è composto da 1 cifra e supponendo k=5 allora k compare 0 volte, 56 è composto
da 2 cifre e k compare 1 volta*/
#include <stdio.h>
int main(){
    int numero=0;
    int contatore=0;
    char K;
    printf("inserisci il numero\nscelta: ");
    scanf("%d", &numero);
    printf("inserisci il valore dato a K\nscelta: ");
    scanf(" %c",&K);
        if(numero>=0 && numero<=9999);
        else printf("numero scelto non valido");
    
    if(K==numero%10)
        numero=numero/10;
        contatore++;
        if(K==numero%10)
            numero=numero/10;
            contatore++;
        if(K==numero%10)
            numero=numero/10;
            contatore++;
        if(K==numero%10)
            numero=numero/10;
            contatore++;
    printf("il valore K compare %d volte",contatore);

    return 0;

        


}




