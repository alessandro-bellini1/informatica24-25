/*calcolare il fattoriale di un numero*/
#include <stdio.h>

void fattoriale(int _n, long *_fatt);

int main(){
    int n;
    long fatt=1;
    do{
        printf("inserisci un valore\nscelta: ");
        scanf("%d",&n);
    }while(n<=0);

    fattoriale(n, &fatt);
    printf("il fattoriale di %d è %ld",n ,fatt);
    return 0;
}

void fattoriale(int _n, long *_fatt){
    for(int i=1; i<=_n; i++)
        *_fatt*=i;
}