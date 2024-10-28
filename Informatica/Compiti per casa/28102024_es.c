/*Creare una sorta di menù( vedi esempio) tramite dei printf per la scelta dell'operazione
da compiere tra due valori generati casualmente( eseguendo lì dove c'è bisogno gli opportuni controlli).
Comunicare il risultato dell'operazione o la scelta dell'utente di non fare niente e uscire dal programma:ES: "Seleziona l'operazione da eseguire: 
    0.  TERMINA
    1.  SOMMA
    2.  DIFFERENZA
    3.  MOLTIPLICAZIONE
    4.  DIVISIONE  */

#include <stdio.h>
#include <stdlib.h>
int main(){
    float n1, n2;
    int scelta;
    printf("-----SCEGLI DAL MENU' L'OPERAZIONE DA FARE-----");
    printf("\n0. TERMINA\n1. SOMMA\n2. DIFFERENZA\n3. MOLTIPLICAZIONE\n4. DIVISIONE\n");
    printf("scegli l'operazione da compiere: ");
    scanf("%d", &scelta);
        srand(time(NULL));
            n1=rand()%50+1;
            n2=rand()%50+1;
        printf("\ni due valori sono: %.2f, %.2f", n1, n2);
        switch (scelta){
            case 0:
                printf("\nil programma termina");
                break;
            case 1:
                printf("\nla somma vale: %.2f", n1+n2);
                break;
            case 2:
                printf("\nla differenza vale: %.2f", n1-n2);
                break;
            case 3:
                printf("\nla moltiplicazione vale: %.2f", n1*n2);
                break;
            case 4:
                printf("\nla divisione vale: %.2f", n1/n2);
                break;
            default:
                printf("\nhai inserito una scelta non valida");
                break;
        }
        return 0;
}
