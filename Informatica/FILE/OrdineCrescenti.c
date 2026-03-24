/*scrivere una funzione che preso in ingresso il nome del file
contenente interi, lo modifichi in modo tale da contenere
gli stessi numeri ma ordinato in senso decrescente*/

#include <stdio.h>
#include <stdlib.h>

void OrdinaFile(char* nome){
    FILE* f;
    int vett[100], n = 0;
    f = fopen(nome, "r");
    if(f == NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }
    while(fscanf(f, "%d", &vett[n]) == 1){
        n++;
    }

    fclose(f);
    
    // Ordina il vettore in senso decrescente con il bubble sort
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(vett[i] < vett[j]){
                int temp = vett[i];
                vett[i] = vett[j];
                vett[j] = temp;
            }
        }
    }

    printf("Numeri ordinati in senso decrescente:\n");
    for(int i = 0; i < n; i++){
        printf("%d \n", vett[i]);
    }

    
}

int main(){
    char nome[20];

    printf("Inserisci il nome del file: (numeri.txt)\n");
    scanf("%s", nome);

    OrdinaFile(nome);

    return 0;
}
