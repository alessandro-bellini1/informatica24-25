/*Calcola l’importo totale da pagare al cinema, sapendo che,
ogni 12 studenti, spetta una gratuità e che per chi ha meno di 15 anni
il biglietto è scontato del 40%: leggi in ingresso il numero di studenti,
il numero di studenti con meno di 15 anni e il costo del biglietto.
*/

#include <stdio.h>
int main(){
	
	float totale,studenti,studenti2,costo;
	totale=0;
	studenti=0;
	studenti2=0;
	costo=0;
				printf("quanto costa il biglietto?");
				scanf("%f",&costo);
				printf("quanti studenti partecipano?");
				scanf("%f",&studenti);
				printf("quanti studenti hanno meno di 15 anni?");
				scanf("%f",&studenti2);
	totale=((costo*studenti2)/100*40)+(studenti*costo)-(studenti2*costo);
				printf("l'importo totale è di: %.2f",totale);
				
	
}