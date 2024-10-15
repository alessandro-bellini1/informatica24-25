/*DATE DUE DATE ESPRESSE IN g, m, a DETERMINARE LA DATA PIU' RECENTE. */
#include <stdio.h>
int main(){
    int giorno, mese, anno, giorno1, mese1, anno1, bisestile, bisestile1;
        printf("inserire la prima data: ");
        scanf("%d%d%d", &giorno,&mese,&anno);
        printf("inserire la seconda data: ");
        scanf("%d%d%d", &giorno1,&mese1,&anno1);
        

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

if(anno1%100==0){
        if(anno1%400==0){
            printf("\nl'anno è bisestile");
            bisestile1=1;
        }
        else{
            printf("\nl'anno non è bisestile");
        }
    }
    else{
        if(anno1%4==0){
            printf("\nl'anno è bisestile");
            bisestile1=1;
        }
    }

    if(mese1>0 && mese1<13){
        if(mese1==2){
            if(giorno1>0 && giorno1<29+bisestile1){
            printf("\nla data è accettabile");
            }
            else{
            printf("\nla data non è accettabile");
            }
        }
        else{
            if(mese1==11 || mese1==4 ||mese1==6 || mese1==9){
                if(giorno1>0 && giorno1<31){
                    printf("\nla data è accettabile");
                }
                else{
            printf("\nla data non è accettabile");
            }
            }
            else{
                if(giorno1>0 && giorno1<32){
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

    if(anno<anno1)
        printf("\nla seconda data è la più recente");
    else if(anno>anno1)
        printf("\nla prima data è la più recente");
    else{//i due anni sono uguali
        if(mese<mese1)
        printf("\nla seconda data è la più recente");
        else if(mese>mese1)
        printf("\nla prima data è la più recente");
        else{//i due mesi sono uguali
            if(giorno<giorno1)
            printf("\nla seconda data è la più recente");
            else if(giorno>giorno1)
            printf("\nla prima data è la più recente");
        }
    }


    

   











}