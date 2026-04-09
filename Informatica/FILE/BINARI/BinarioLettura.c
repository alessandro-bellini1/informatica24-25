/*Lettura un file binario*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("numeri.bin", "rb");
    int numeri[3];
    if(fp == NULL){
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    fread(numeri, sizeof(int), 3, fp);
    fclose(fp);
    for(int i = 0; i < 3; i++){
        printf("%d ", numeri[i]);
    }
    return 0;
}