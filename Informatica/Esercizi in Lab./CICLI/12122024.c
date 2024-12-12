/*Dati N numeri in input (con N chiesto all'utente strettamente maggiore di 5), calcolare
e mostrare la somma dei numeri negativi e dei numeri positivi*/
#include <stdio.h>
int main(){

    int N=0, num=0 ,sommaP=0, sommaN=0;
    do{
        printf("inserisci il numero di valori che vengono inserire (più di 5)\nScelta: ");
        scanf("%d",&N);
    }while(N<=5);
    
    for(int i=0; i<N; i++){
        printf("inserisci un valore\nScelta: ");
        scanf("%d",&num);
        if(num>0)
            sommaP+=num;
        else if(num<0){
        sommaN+=num;
        }
        else printf("il valore è uguale a 0");
    }
    printf("la somma dei numeri postivi è %d\nla somma dei numeri negativi è %d",sommaP, sommaN);
}
