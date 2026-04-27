# Gestione dei file di testo, binari e strutturati

## Funzioni principali per la gestione dei file
In C, la gestione dei file avviene principalmente attraverso luso di funzioni della libreria standard `<stdio.h>`. Ecco alcune delle funzioni più comuni e i parametri principali:
- `FILE *fopen(const char *nomefile, const char *modalita)`: apre un file; `nomefile` è il nome del file e `modalita` è la modalità di apertura (`"r"`, `"w"`, `"rb"`, `"wb"`, ecc.).
- `int fclose(FILE *fp)`: chiude un file aperto; `fp` è il puntatore al file.
- `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *fp)`: legge dati binari; `ptr` è il buffer di destinazione, `size` è la dimensione di ogni elemento, `nmemb` è il numero di elementi da leggere e `fp` è il file.
- `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp)`: scrive dati binari; `ptr` è il buffer sorgente, `size` è la dimensione di ogni elemento, `nmemb` è il numero di elementi da scrivere e `fp` è il file.
- `int fprintf(FILE *fp, const char *format, ...)`: scrive dati formattati su un file di testo; `fp` è il file, `format` è la stringa di formato e gli argomenti successivi sono i valori da stampare.
- `int fscanf(FILE *fp, const char *format, ...)`: legge dati formattati da un file di testo; `fp` è il file, `format` è la stringa di specifica e gli argomenti successivi sono i puntatori alle variabili dove salvare i dati.
- `char *fgets(char *str, int n, FILE *fp)`: legge una riga da un file di testo; `str` è il buffer, `n` è il numero massimo di caratteri da leggere e `fp` è il file.
- `int fputs(const char *str, FILE *fp)`: scrive una stringa su un file di testo; `str` è la stringa e `fp` è il file.
- `int feof(FILE *fp)`: verifica la fine del file; `fp` è il file.
- `int ferror(FILE *fp)`: verifica la presenza di errori sul file; `fp` è il file.
- `int fseek(FILE *fp, long offset, int whence)`: sposta il cursore del file; `offset` è lo spostamento e `whence` indica la posizione di riferimento (`SEEK_SET`, `SEEK_CUR`, `SEEK_END`).
- `long ftell(FILE *fp)`: ottiene la posizione corrente nel file; `fp` è il file.
- `void rewind(FILE *fp)`: riporta il cursore all'inizio del file; `fp` è il file.

## Modalità di apertura del file
- `r`: apre in lettura testo.
- `w`: apre in scrittura testo, cancellando il contenuto esistente.
- `a`: apre in aggiunta testo, scrivendo alla fine.
- `rb`: apre in lettura binaria.
- `wb`: apre in scrittura binaria.
- `ab`: apre in aggiunta binaria.

## File di testo
- I file di testo contengono caratteri leggibili e sono usati per dati separati da spazi o righe.
- Si usano `fprintf`, `fscanf`, `fgets`, `fputs`.
- Per leggere una riga: `fgets(buffer, size, fp)`.
- Per scrivere una riga: `fprintf(fp, "%s\n", str);` o `fputs(str, fp);`.

## File binari
- I file binari memorizzano i dati così come sono in memoria, senza formattazione testuale.
- Si usano `fread` e `fwrite` con la dimensione in byte.
- Sintassi:
  - `fread(&variabile, sizeof(tipo), 1, fp);`
  - `fwrite(&variabile, sizeof(tipo), 1, fp);`
- Usare il formato binario quando si devono salvare numeri, struct o blocchi di memoria.

## File strutturati
- I file strutturati contengono record con campi organizzati, spesso definiti da `struct` in C.
- Possono essere salvati come testo con formato leggibile o come binario con `fwrite`/`fread`.
- Esempio di struct:
  ```c
  typedef struct {
      int id;
      char nome[30];
      float media;
  } Studente;
  ```
- Salvare un array di struct in binario:
  ```c
  Studente v[10];
  fwrite(v, sizeof(Studente), 10, fp);
  ```
- Leggere un record alla volta:
  ```c
  Studente s;
  while (fread(&s, sizeof(Studente), 1, fp) == 1) {
      // usa s
  }
  ```

## Consigli pratici per il codice
- Controlla sempre che `fopen` non ritorni `NULL`.
- Chiudi sempre il file con `fclose(fp)`.
- Prima di leggere, verifica `feof(fp)` e `ferror(fp)`.
- Per file testuali con `fscanf`, fai attenzione agli spazi e ai ritorni a capo.
- Per file binari, evita di miscelare letture/scritture testuali e binarie sullo stesso file senza riaprire.

## Funzioni utili riassunte
- `fopen`, `fclose`, `fprintf`, `fscanf`, `fgets`, `fputs`, `fread`, `fwrite`
- `feof`, `ferror`, `fseek`, `ftell`, `rewind`
- `sizeof(tipo)` per calcolare i byte da leggere/scrivere
- `struct` per organizzare dati strutturati

## Esempio rapido
- File testo: apri con `fopen("dati.txt", "w");`, scrivi con `fprintf`, chiudi con `fclose`.
- File binario: apri con `fopen("dati.bin", "wb");`, scrivi con `fwrite`, chiudi con `fclose`.
- Struct: definisci il tipo, poi usa `fwrite(&record, sizeof(record), 1, fp)` per il salvataggio e `fread(&record, sizeof(record), 1, fp)` per il caricamento.

## Nota
- I file testuali sono ideali per output leggibile e dati separati da spazi/righe.
- I file binari sono ideali per prestazioni e precisione nella memorizzazione di dati numerici e strutture.
- I file strutturati possono essere gestiti sia come testo che come binario a seconda delle esigenze.
