/*progettate un algoritmo che legga un numero B<A
e scriva quante volte A è divisibile per B
Esempio: A=162 e B=3 A è divisibile 4 volte per B*/
#include <stdio.h>
int main(){

    int A, B, k, r=0, cnt=0;

    do{
        printf("inserisci un valore per A\nscelta: ");
        scanf("%d",&A);
        printf("inserisci un valore per B\nscelta: ");
        scanf("%d",&B);
    }while(A<B);

    while(r==0){
        if(A%B==0)
        A=A/B;
        else
        r++;
        if(r!=1)
        cnt++;
    }
    printf("A è divisibile per %d volte per B",cnt);

}