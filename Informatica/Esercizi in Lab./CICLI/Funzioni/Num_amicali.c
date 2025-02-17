/*data una sequenza di valori, verificare se i valori presi a coppie risultano essere amicali, si termina quando uno dei valori è 0*/

#include <stdio.h>
void Num_amicali(int *_somma1, int *_somma2, int *_n);

int main(){
    int n1, n2, somma1=0, somma2=0;
    printf("inserisci un valore al primo numero\nscelta: ");
    scanf("%d", &n1);
    printf("inserisci un valore al secondo numero\nscelta: ");
    scanf("%d", &n2);
    Num_amicali(&somma1, &somma2);


}

void Num_amicali(int *_somma1, int *_somma2){
    for(int i=1; i<=n1; i++){
        if(n1%i==0)
        *_somma1+=i;
    }
    if(*_somma1==n2)
    printf("la somma dei divisori del primo numero è uguale al secondo numero %d",somma1);
    for(int j=1; j<=n2; j++){
        if(n2%j==0)
        somma2+=j;
    }
    if(somma2==n1)
    printf("la somma dei divisori del secondo numero è uguale al primo numero %d",somma2);
}