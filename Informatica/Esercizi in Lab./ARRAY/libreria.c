/*
    Sviluppiamo le funzioni
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "libreria.h" //prototipi delle funzioni

void richiediValori(int vet[], int dim){
    int n=0, i=0;

    while(i<dim){
        printf("inbserisci un valore\nscelta: ");
        scanf("%d", &n);
        if(n%2==0){
            vet[i]=n;
            i++;
        }
    }

}
    
void scambiaVettori(int vet[], int vet2[], int dim){
    int temp;
    for(int i=0; i<dim; i++){
        temp=vet[i];
        vet[i]=vet2[i];
        vet2[i]=temp;
    }
}

void stampaVettori(int vet[], int vet2[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c",vet[i],sep);
    }
    printf("\n");
    for(int i=0; i<dim; i++){
        printf("%d%c",vet2[i],sep);
    }
}

void caricaCasuale(int vet[], int dim, int min, int max){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        vet[i]=rand()%(max-min)+min;
    }
}

void riempiVettoreCasuale(int vet[], int vet2[], int dim, int minimo, int massimo){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        vet[i]=rand()%(massimo-minimo+1)+minimo;
        vet2[i]=rand()%(massimo-minimo+1)+minimo;
    }
}
void calcolaMedia(int vet[], int dim){
    int Somma=0, Media=0;
    for(int i=0; i<dim; i++){
        Somma+=vet[i];
        
    }
    Media+=Somma/dim;
    printf("la media dei valori casuali è: %d",Media);
}

int contaOccorrenze(int vettore[], int dim, int valore){
    int cnt=0;

    for(int i=0; i<dim; i++){
        if(vettore[i] == valore){
            cnt++;
        }
    }
    return cnt;
}


int ricercaSequenziale(int *vettore, int dim, int valore){
    for(int i = 0; i<dim; i++){
        if(vettore[i]==valore){
            return i;
        }
    }
    return -1;

}

int ricercaBinaria(int vettore[], int dim, int estInf, int estSup, int valore){
    int media = (estSup+estInf)/2;
    if(estInf > estSup)
        return -1;
    if(vettore[media]== valore)
        return media;
    if(vettore[media] > valore)
        return ricercaBinaria( vettore,dim, estInf, media-1, valore);
    else 
        return ricercaBinaria( vettore,dim, media+1, estSup, valore);
}

void shiftDx (int vett[], int dim, int pos){
    for(int i=dim; i>pos; i--){
        vett[i]=vett[i-1];
    }
}
int trovaPosizione (int vett[], int dim, int num){
    int i=0;
    while(vett[i]<num && i<dim){
        i++;
    }
    return i;
}

void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo) {
    srand(time(NULL));
    int num, pos;
    vett[0] = rand()%(massimo-minimo+1)+minimo;
    for(int i=1; i<dim; i++){
        num = rand()%(massimo-minimo+1)+minimo;
        pos = trovaPosizione(vett, i, num); 
        shiftDx(vett, i, pos);
        vett[pos] = num;
    }
}
