/*Il programma legge tre numeri e dice se possono essere le lunghezze
 dei lati di un triangolo (perché un triangolo possa essere tale la somma
  di ogni coppia lati deve essere maggiore dell’altro)*/

#include <stdio.h>
int main(){
    int n1, n2, n3;
    printf("inserire i 3 valori: ");
    scanf("%d%d%d", &n1,&n2,&n3);
    if(n1+n2>n3&&n2+n3>n1&&n3+n1>n2)
        printf("i lati possono essere le lunghezze dei lati di un triangolo");
        else
        printf("i lati non possono essere le lunghezze dei lati di un triangolo");
}
