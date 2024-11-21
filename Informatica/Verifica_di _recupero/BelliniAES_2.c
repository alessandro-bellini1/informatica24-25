/*DATO UN NUMERO N POSITIVO NON NULLO MINORE DI 20 E UN NUMERO C(tra
1 e 9) STAMPARE TUTTI I MULTIPLI DI C MINORI DI N.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
int num, c, multiplo;
srand(time(NULL));
num = rand()%19-1+1;
c = rand()%9-1+1;
printf("i due valori sono \nnumero: %d\nc: %d\n",num,c);
multiplo=c+c;
    if(multiplo<num){
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    multiplo=multiplo+c;
    if(multiplo<num)
    printf("%d\n",multiplo);
    }
    else printf("non ci sono multipli minori del numero");
}