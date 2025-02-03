/*dato un valore convertirlo da decimale a binario
*/

#include <stdio.h>

long converti(int _n);

int main(){
    int n;
    long conv;
    do{
        printf("inserisci un valore\nscelta: ");
        scanf("%d",&n);
    }while(n<=0);
    
    conv=converti(n);

}

long converti(int _n){
    int quoz=_n, resto=0,cnt=0, _conv=0;
    
    while(_n!=0){
        resto=quoz%2; 
        quoz/=2;
        _conv=pow(10,cnt);
        cnt++;
    }
}

