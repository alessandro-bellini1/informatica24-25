/*  data una data in formato gg mm aaaa
verificare se la data è accettabile */
#include <stdio.h>
int main(){

    int giorno=0;
    int mese=0;
    int anno=0;
    int bisestile=0;

    //richiesta degli input
    printf("inserisci il giorno: ");
    scanf("%d", &giorno);
    printf("inserisci il mese: ");
    scanf("%d", &mese);
    printf("inserisci l'anno: ");
    scanf("%d", &anno);

    //controllo dell'anno
    //un anno è bisestile se è multiplo di 4 ma nom di 100 oppure multiplo di 400
    if(anno%100==0){
        if(anno%400==0){
            printf("l'anno è bisestile");
            bisestile=1;
        }
        else{
            printf("\nl'anno non è bisestile");
        }
    }
    else{
        if(anno%4==0){
            printf("l'anno è bisestile");
            bisestile=1;
        }
    }
    //controllo del mese e del giorno
    if(mese>0 && mese<13){
        if(mese==2){
            if(giorno>0 && giorno<29+bisestile){
            printf("\nla data è accettabile");
            }
            else{
            printf("\nla data non è accettabile");
            }
        }
        else{
            if(mese==11 || mese==4 ||mese==6 || mese==9){
                if(giorno>0 && giorno<31){
                    printf("\nla data  accettabile");
                }
                else{
            printf("\nla data non è accettabile");
            }
            }
            else{
                if(giorno>0 && giorno<32){
                    printf("\nla data  accettabile");
                }
                else{
            printf("\nla data non è accettabile");
            }
        }
    }
    }
    else{
        printf("\nla data non è accettabile");
    }
}