//scrivi su un file
#include <stdio.h>

int main(){
    FILE *f = fopen("dati.txt", "w");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fprintf(f, "Ciao, mondo!\n");
    fprintf(f, "Il numero: %d\n", 10);
    fclose(f);
    return 0;
}