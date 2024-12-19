/*  Dato un numero N calcolare il suo quadrato sommando i primi N numeri dispari
    esempio: N=7 7^2=49
    1 3 5 7 9 11 13
*/
#include <stdio.h>
int main(){
int N=0, disp=1, quadrato=0;
do{
    printf("inserisci un numero\nscelta: ");
    scanf("%d", &N);
}while(N<0);
for(int i=0;i<N;i++){
    quadrato+=disp;
    printf("%d+",disp);
    disp+=2;
}
printf("\nil quadrato di %d è %d", N, quadrato);
return 0;
}