/*GENERATA UNA DATA TRA L’ANNO 2000 E L’ANNO 2024 AD OGGI E SAPENDO
CHE GIACOMO HA 20 GIORNI PER CONSEGNARE IL LAVORO ASSEGNATO
COMUNICARE LA DATA DI CONSEGNA.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
srand(time(NULL));
int giorno, mese, anno, bisestile;
giorno = rand()%30-1+1;
if(mese==2&&giorno<29+bisestile)
printf("il giorno non è accettabile");
if(mese==11||mese==4||mese==6||mese==9)

mese = rand()%12-1+1;
anno = rand()%(2024-2000+1)+2000;
printf("%d/%d/%d", giorno, mese, anno);

    if(anno%100==0){
        if(anno%400==0){
            printf("\nl'anno è bisestile");
            bisestile=1;
        }
        else{
            printf("\nl'anno non è bisestile");
        }
    }
    else{
        if(anno%4==0){
            printf("\nl'anno è bisestile");
            bisestile=1;
        }
    }

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
                    printf("\nla data è accettabile");
                }
                else{
                    printf("\nla data non è accettabile");
                }
            }
            else{
                if(giorno>0 && giorno<32){
                    printf("\nla data è accettabile");
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