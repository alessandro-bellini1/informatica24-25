#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char titolo[30];
	char autore[30];
	int isbn;
	int copie_totali;
	int copie_disponibili;
	struct Data{
	int giorno_prestito;
	int mese_prestito;
	int anno_prestito;
	int giorno_restituzione;
	int mese_restituzione;
	int anno_restituzione;
	}Data;
}Libro;

Libro* inserisci_libro(Libro* libreria, int *n){
	Libro nuovo_libro;
	printf("inserisci titolo ");
	fgets(nuovo_libro.titolo,30,stdin);
	printf("inserisci l autore ");
	fgets(nuovo_libro.autore,30,stdin);
	printf("inserisci ISBN ");
	scanf("%d", &nuovo_libro.isbn);
	getchar();
	printf("inserisci copie totali ");
	scanf("%d", &nuovo_libro.copie_totali);
	getchar();
	nuovo_libro.copie_disponibili = nuovo_libro.copie_totali;
	
	libreria = (Libro*)realloc(libreria, ((*n)+1)*sizeof(Libro));
	if(libreria == NULL){
        printf("errore di allocazione.");
        exit(1);
    }
    libreria[*n] = nuovo_libro;
    (*n)++;
    return libreria;
}

void prendere_prestito(Libro*libreria, int *n){
	int codice, i;
	printf("\nscrivi l ISBN del libro da prendere in prestito ");
	scanf("%d", &codice);
	getchar();
	for(i=0; i<*n; i++){
		if(libreria[i].isbn != codice){
			printf("\nlibro inesistente"); 
			return;
		}	
		if(libreria[i].copie_disponibili==0){
			return;
		}	
		else{
			printf("\ninserisci la data del prestito \n");
			printf("giorno ");
			scanf("%d", &libreria[i].Data.giorno_prestito);
			printf("mese ");
			scanf("%d", &libreria[i].Data.mese_prestito);
			printf("anno ");
			scanf("%d", &libreria[i].Data.anno_prestito);
			
			printf("\ninserisci la data della restituzione \n");
			printf("giorno ");
			scanf("%d", &libreria[i].Data.giorno_restituzione);
			printf("mese ");
			scanf("%d", &libreria[i].Data.mese_restituzione);
			printf("anno ");
			scanf("%d", &libreria[i].Data.anno_restituzione);
            libreria[i].copie_disponibili = libreria[i].copie_disponibili-1;
		}
	}
	
}

void stampa_libri(Libro* libreria, int n){
    printf("\n---elenco libri---\n");
    int i;
    for(i=0;i<n;i++){
        printf("%d) Titolo %s", i+1, libreria[i].titolo);
        printf("%d) Autore %s", i+1, libreria[i].autore);
        printf("%d) ISBN %d\n", i+1, libreria[i].isbn);
        printf("%d) Copie disponibili %d\n", i+1, libreria[i].copie_disponibili);
    }
}

void stampa_prestiti(Libro*libreria, int n){
	int i;
	printf("Libri in prestito: \n");
    for(i=0;i<n;i++){
    	if(libreria[i].copie_totali!=libreria[i].copie_disponibili){
	    	printf("%d) Titolo %s", i+1, libreria[i].titolo);
	        printf("%d) Autore %s", i+1, libreria[i].autore);
	        printf("%d) ISBN %d\n", i+1, libreria[i].isbn);
	        printf("%d) Copie disponibili %d\n", i+1, libreria[i].copie_disponibili);
    	}
    }
}

void trova_libro (Libro* libreria, int n){
	int codice, i;
	printf("\nscrivi l ISBN del libro ");
	scanf("%d", &codice);
	for(i=0; i<n; i++){
		if(libreria[i].isbn == codice){
			printf("Libro trovato: \n");
			printf("Titolo %s", libreria[i].titolo);
	        printf("Autore %s", libreria[i].autore);
	        printf("ISBN %d\n", libreria[i].isbn);
	        printf("Copie disponibili %d\n", libreria[i].copie_disponibili);
		}
	}
}

void libri_scaduti(Libro*libreria, int n){
	int i, giorno, mese, anno;
	printf("inserisci data di oggi \n");
	printf("giorno: ");
	scanf("%d", &giorno);
	getchar();
	printf("mese: ");
	scanf("%d", &mese);
	getchar();
	printf("anno: ");
	scanf("%d", &anno);
	getchar();
	
	printf("Libri con prestito scaduto: \n");
	
	for(i=0; i<n; i++){
		if(anno>libreria[i].Data.anno_restituzione){
			printf("%d) Titolo %s", i+1, libreria[i].titolo);
	        printf("%d) Autore %s", i+1, libreria[i].autore);
	        printf("%d) ISBN %d\n", i+1, libreria[i].isbn);
	        printf("%d) Copie disponibili %d\n", i+1, libreria[i].copie_disponibili);
	    }
	    else if(anno==libreria[i].Data.anno_restituzione && mese>libreria[i].Data.mese_restituzione){
	    	printf("%d) Titolo %s", i+1, libreria[i].titolo);
	        printf("%d) Autore %s", i+1, libreria[i].autore);
	        printf("%d) ISBN %d\n", i+1, libreria[i].isbn);
	        printf("%d) Copie disponibili %d\n", i+1, libreria[i].copie_disponibili);
		}
		else if(anno==libreria[i].Data.anno_restituzione  && mese==libreria[i].Data.mese_restituzione && giorno>libreria[i].Data.giorno_restituzione){
			printf("%d) Titolo %s", i+1, libreria[i].titolo);
	        printf("%d) Autore %s", i+1, libreria[i].autore);
	        printf("%d) ISBN %d\n", i+1, libreria[i].isbn);
	        printf("%d) Copie disponibili %d\n", i+1, libreria[i].copie_disponibili);
		}
	}
	
	
	
	
	
}

int main(){
	Libro*libreria = NULL;
	int numero_libri = 0;
	int scelta;
	do{
		printf("\n\t\t---|MENU|---\n");
		printf("1) aggiungi un libro\n");
		printf("2) prendere un libro in prestito\n");
		printf("3) visualizzare l elenco dei libri\n");
		printf("4) visualizzare i libri in prestito\n");
		printf("5) cerca il libro tramite ISBN\n");
		printf("6) visualizza i libri con prestito scaduto\n");
		printf("7) esci\n");
		scanf("%d", &scelta);
		getchar();
		
		switch(scelta){
			case 1:
				libreria = inserisci_libro(libreria, &numero_libri);
				break;
			
			case 2:
				prendere_prestito(libreria, &numero_libri);
				break;
			
			case 3: 
				stampa_libri(libreria, numero_libri);
				break;
				
			case 4:
				stampa_prestiti(libreria, numero_libri);
				break;
				
			case 5: 
				trova_libro(libreria, numero_libri);
				break;
				
			case 6:
				libri_scaduti(libreria, numero_libri);
				break;
			
			case 7:
				printf("uscita dal programma...");
				break;
				
			default:
				printf("scelta non valida");
		}
		
	}while(scelta != 7);

	return 0;
}