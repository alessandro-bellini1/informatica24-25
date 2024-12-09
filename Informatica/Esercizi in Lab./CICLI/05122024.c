/*calcolare il quoziente fra due numeri applicando il
metodo delle sottrazioni sucessive*/


#include <stdio.h>

int main (){

int num1,num2,num3,quoz=0,cnt=0;

do{
    printf("inserisci il primo numero: ");
    scanf("%d", &num1);
}while (num1<=0);

do{
    printf("inserisci il secondo numero: ");
    scanf("%d",&num2);
}while (num2<=0);

if(num1<num2){
    num1=num3;
    num2=num1;
    num2=num3;
}
quoz=num1;

while(quoz>num2){
    quoz=quoz-num2;
    cnt++;
}

printf("\nil risultato è %d mentre il resto è %d", quoz,cnt);

}