/*costruire un vettore di N elementi con valori letti da tastiera*/
#include <stdio.h>
#define MAX 3
int main(){
    int v[MAX];
    for(int i=0; i<MAX; i++){
        do{printf("inserisci il valore della cella\nscelta: ");
        scanf("%d", &v[i]);
        }while(v[i]<=0);
    }
}