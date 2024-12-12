/*Dati in input 10 numeri interi determinare il valore maggiore e quante volte compare.*/
#include <stdio.h>
int main(){
    int num=0, cnt=0, max=0;
    
    for(int i=0; i<10; i++){
        printf("inserisci un valore\nScelta: ");
        scanf("%d",&num);
        if(num>max){
        max=num;
        cnt=0;
        }
        if(num==max)
        cnt++;
    }
    printf("il valore maggiore è %d e compare %d volte", max, cnt);
}