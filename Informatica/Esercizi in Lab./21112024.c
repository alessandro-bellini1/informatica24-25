/*Dato un numero stampare tutto i suoi divisori*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
int num, divisore;
printf("inserisci un numero\nscelta: ");
scanf("%d", &num);

while(divisore<=num/2){
    if(num%divisore==0)
    printf("%d è un divisore di %d\n", divisore, num);
    divisore++;
}
printf("il numero è divisibile per 1 e %d", num);



}