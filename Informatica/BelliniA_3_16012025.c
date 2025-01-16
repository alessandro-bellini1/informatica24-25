/*Leggere una serie di numeri interi passati dall’utente dopo aver eseguito una scelta che determini se
stampare i valori in senso crescente o decrescente e fermandosi al primo ‘0’ , tale da stampare solo i
valori che rendono la serie crescente o decrescente e restituire quanti numeri erano stati inseriti.
Esempio: scelta=crescente - l’utente inserisce: 8 35 3 8 46 - numeri inseriti: 5.*/
#include <stdio.h>
int main(){
    int n1, n2, num=0, cnt=2;
    do{
        printf("inserisci il primo valore\nscelta: ");
        scanf("%d", &n1);
        printf("inserisci il secondo valore\nscelta: ");
        scanf("%d", &n2);
    }while(n1==n2);
    if(n1<n2){
        do{
            printf("inserisci i valori in ordine crescente: ");
            scanf("%d",&num);
            if(num>n2){
            cnt++;
            printf("%d ",num);
            }
        }while(num!=0);
    }
    else{
        do{
            printf("inserisci i valori in ordine decrescente: ");
            scanf("%d",&num);
            if(num<n2){
            cnt++;
            printf("%d ",num);
            }
        }while(num!=0);
        
    }
    printf("numeri inseriti sono %d",cnt);
}