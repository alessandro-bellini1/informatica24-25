/*Calcola il costo sostenuto dalla scolaresca per andare a teatro
sapendo che il biglietto ordinario costa 12 euro, i 2 docenti accompagnatori
hanno lo sconto del 50% e che il numero degli alunni deve essere letto in INPUT.
*/

#include <stdio.h>

int main(){
	
	int alunni,docenti,totale;
	alunni=0;
	docenti=0;
	totale=0;
	docenti=(12/2)*2;
	printf("inserisci il numero degli alunni");
	scanf("%d",&alunni);
	alunni=alunni*12;
	totale=docenti+alunni;
	printf("il costo sostenuto dalla scolaresca vale: %d",totale);

	
	
}
