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
    printf("%d",fatt);
    return 0;
}

void fattoriale(int _n, long *_fatt){
    int i;
    for(i=1; i<=_n; i++)
        *_fatt*=i;
}