/*dato il raggio calcolare la circonferenza e l'area del cerchio 
circonferenza = 2*R*3,14 
area = R^2*3,14
*/
#include <stdio.h>
#define PG 3.14

void area(int _R, float *_A);
void circonferenza(int _R, float *_C);

int main(){
    float R, C, A;
    
    do{
        printf("inserisci un valore\nscelta: ");
        scanf("%f",&R);
    }while(R<=0);

    area(R, &A);
    circonferenza(R, &C);
    printf("la circonferenza del cerchio vale: %.2f \nmentre l'area vale: %.2f",C, A);
}
void area(int _R, float *_A){
    *_A=(_R*_R)*PG;
}
void circonferenza(int _R, float *_C){
    *_C=_R*2*PG;
}
