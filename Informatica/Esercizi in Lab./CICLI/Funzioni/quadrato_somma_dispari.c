/* si scriva un proggramma che letto un numero intero positivo dallo standard
input, visualizzi a terminale il quadrato del numero stesso facendo uso soltanto
di operazioni di somma
il quadrato di ogni numero intero positivo N può essere costruito sommando tra loro
i primi N numeri dispari. 
Es: N = 5 = 1+3+5+7+9 = 25*/
#include <stdio.h>

void calcoloQuadrato(int _n, int *_quadrato);

int main(){
    int n, quadrato=0;
    do{
        printf("inserisci un valore\nscelta: ");
        scanf("%d",&n);
    }while(n<=0);

    calcoloQuadrato(n, &quadrato);
    printf("\n= %d",quadrato);
    return 0;
}

void calcoloQuadrato(int _n, int *_quadrato){
    int cnt=1;
    for(int i=1; i<=_n; i++){
        if(cnt%2==1){
            printf("%d + ",cnt);
            *_quadrato+=cnt;
            cnt+=2;
        }
    }
}