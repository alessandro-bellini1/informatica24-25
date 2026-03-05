//scrittura e lettura su file formattato
#include <stdio.h>

int main(){
    //scrivi su un file
    FILE *f = fopen("dati.txt", "w");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fprintf(f, "%s %d %.2f\n", "Luca", 12, 6.5);
    fclose(f);

    //leggi dal file dati.txt
    f = fopen("dati.txt", "r");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    char nome[100];
    int eta;
    float media;
    fscanf(f, "%s %d %f", nome, &eta, &media);
    printf("Nome: %s\nEtà: %d\nMedia: %.2f\n", nome, eta, media);
    fclose(f);

    return 0;
}