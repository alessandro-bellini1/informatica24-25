/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/
#include <stdio.h>
#include <time.h>
#define N 4  // Dimensione della matrice quadrata

void caricaMat(int (*_mat)[N]){
    printf("Matrice iniziale: \n");
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            _mat[i][j] = rand()%30 + 1;
    return 0;
}

void stampa_matrice(int (*_mat[N])){
    for(int i=0; i< N; i++)
        for(int j=0; j< N; j++){
            printf("%d  ", _mat[i][j]);
            printf("\n");
        }
    
    
}

void scambioDiag(int (*_mat)[N]){
    for(int i=0; i<N; i++){
        int temp = _mat[i][i];
        _mat[i][i] = _mat[i][N-1-i];
        _mat[i][N-1-i] = temp;
    }
}

int main(){
    stampa_matrice();
    printf("\nMatrice dopo lo scambio delle diagonali:\n");
    stampa_matrice(matrice);

    return 0;
}