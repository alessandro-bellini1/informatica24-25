/*Calcola il resto ricevuto dal benzinaio: 
dopo aver inserito il numero di litri di carburante
introdotto nel motorino e il costo al litro della benzina, il programma
deve visualizzare l’importo da pagare.
L’utente digita l’importo di una banconota di valore superiore a tale
importo e il programma visualizza il resto
della banconota che questi deve ricevere.
*/
#include <stdio.h>

int main(){
	
	float litri,costo,importo,pagamento,resto;
	litri=0;
	costo=0;
	importo=0;
	pagamento=0;
	resto=0;
			printf("inserire la quantità di litri da versare");
			scanf("%f",&litri);
	costo=3;
			importo=costo*litri;
			printf("L'importo da pagare è di: %.2f\n",importo);
			printf("Inserire un pagamento superiore\n");
			scanf("%f",&pagamento);
	resto=pagamento-importo;
			printf("il resto è di: %.2f",resto);
	
}