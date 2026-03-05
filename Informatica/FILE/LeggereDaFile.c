//leggi dal file dati.txt
#include <stdio.h>

int main(){
    FILE *f = fopen("dati.txt", "r");
    if(f == NULL){
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), f) != NULL){
        printf("%s", buffer);
    }
    fclose(f);
    return 0;
}