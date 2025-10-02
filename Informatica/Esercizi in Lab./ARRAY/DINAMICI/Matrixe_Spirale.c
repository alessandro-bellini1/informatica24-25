#include <stdio.h>
#include <stdlib.h>

void RiempiSpirale(int n, int m, int **matrix) {
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    int num = 1;

    while (num<= n * m) {
        //sinistra verso destra
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num++;
        }
        top++;

        //alto verso basso
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;

        //destra verso sinistra
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        //basso verso alto
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
}

void StampaMatrice(int n, int m, int **matrix) {
    printf("Matrice in ordine spirale:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, m;
    printf("Inserisci il numero di righe: ");
    scanf("%d", &n);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &m);

    // Allocazione dinamica della matrice
    int **matrix = malloc(n * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Errore di allocazione memoria.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Errore di allocazione memoria.\n");
            // Libera la memoria già allocata
            for (int k = 0; k < i; k++) free(matrix[k]);
            free(matrix);
            return 1;
        }
    }

    RiempiSpirale(n, m, matrix);
    StampaMatrice(n, m, matrix);

    // Libera la memoria allocata
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}