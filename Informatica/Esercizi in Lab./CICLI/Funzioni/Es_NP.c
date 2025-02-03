/*trova i primi 3 numeri perfetti cioè la somma dei divisori è uguale al numero, creare una funzione che restituisce la somma dei divisori*/

#include <stdio.h>

void printSommaDivisori(int _somma);

int main(){
	int somma;
	printSommaDivisori(somma);
	return 0;
}

void printSommaDivisori(int _somma){
	int i, j;
	for(i=1; i<=500; i++){
		for(j=1; j<i; j++){
			if(i%j==0)
			_somma+=j;
		}
		if(i==_somma)
		printf("%d\t", _somma);
		_somma=0;
	}
}