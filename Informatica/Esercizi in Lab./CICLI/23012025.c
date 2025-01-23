/*DATI  DUE  NUMERI  A  PIU' CIFRE(STESSO NUMERO DI CIFRE) SCAMBIARE TRA DI LORO LE CIFRE DI POSIZIONE PARI*/
#include <stdio.h>
int main(){
    int n1, n2, cnt=0, cnt2=1, c1=0, c2=0, temp=0, n3=0, n4=0;
    do{
        printf("inserisci un valore maggiore di 9\nscelta: ");
        scanf("%d", &n1);
    }while(n1<=9||n1>=10000);
    do{
        printf("inserisci un'altro valore maggiore di 9\nscelta: ");
        scanf("%d", &n2);
    }while(n2<=9||n2>=10000);


    for(int i=1; i<=4; i++){
        c1=n1%10;
        c2=n2%10;
        cnt++;
        if(i>1)
        cnt2*=10;
        if(cnt%2==0){
            temp=c1;
            c1=c2;
            c2=temp;
            n3+=c1*cnt2;
            n4+=c2*cnt2;
        }else{
            n3+=c1*cnt2;
            n4+=c2*cnt2;
        }
        n1=n1/10;
        n2=n2/10;
    }
    printf("il primo numero diventa: %d mentre il secondo: %d",n3,n4);
}