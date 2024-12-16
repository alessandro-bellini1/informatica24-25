/*stampa i primi N numeri dispari successivi al numero A*/
#include <stdio.h>
int main(){
    int N=0, A=0;
    do{
        printf("inserisci un numero che appartiene ad N\nscelta: ");
        scanf("%d",&N);
        printf("inserisci un numero che appartiene ad A\nscelta: ");
        scanf("%d",&A);
    }while(N<0 || A<0);
    A++;
    for(int i=1; i<=N; i++){
        if(A%2!=0)
        printf("%d,",A);
        else i--;
        A++;
    }



}