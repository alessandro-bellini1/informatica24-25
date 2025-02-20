/* datoo un valore stampare i suoi fattori 
ES: 28 = 2*2*7      2, 2, 7 
28/2
14 */
#include <stdio.h>
void calcoloFattore(int _fattore, int _num);


int main(){
    int fattore=0, num;

    do{
        printf("inserisci un numero\nscelta: ");
        scanf("%d",&num);
    }while(num<1);
    calcoloFattore(fattore, num);
}
void calcoloFattore(int _fattore, int _num){
    for(int i=2; i<=_num;){
        if(_num%i==0){
            _num/=i;
            _fattore=i;
            printf("%d\t", _fattore);
        }
        else i++;
    }
}