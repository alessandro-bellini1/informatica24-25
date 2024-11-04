#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int sceltautente=0, sceltacomputer=0;

    sceltaComputer = rand()%3+1;
    printf("scegli tra:\n1. Sasso\n2. Carta\n3. Forbice\nScelta: ")
    scanf("%d", &sceltautente);

    if(sceltautente==1 || sceltautente==2 || sceltautente==3){
        if(sceltacomputer==sceltautente){
            printf("Pareggio!");
        }   else if(sceltautente==1 && sceltacomputer=3){
                printf("Hai vinto!");
            }   else if(sceltautente==2 && sceltacomputer=1){
                    printf("Hai vinto!");
                }   else if(sceltautente==3 && sceltacomputer=2){
                        printf("Hai vinto!");
                    }   else{
                            printf("Hai perso!");
                        }
            
    } else{
        printf("Scelta non valida.");
    }

}