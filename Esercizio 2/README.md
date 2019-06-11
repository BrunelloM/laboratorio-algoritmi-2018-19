# Esercizio 2 (Implementazione e utilizzo della funzione edit_distance):

## Compilazione (tramite script):
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 1).
2. Dare i permessi necessari all'esecuzione dello script `build.sh` tramite il comando `chmod +777 ./build.sh`.
3. Eseguire `./build.sh`.

## Compilazione (tramite utility make):
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 1).
2. Eseguire il comando `mkdir -p ./bin ./obj`, il quale crea le cartelle necessarie alla compilazione solo in caso esse non siano gia' presenti.
3. Lanciare il comando `make all`.

## Esecuzione:
Durante il processo di compilazione verranno creati 3 files eseguibili:
* `edit_distance_main` e' il programma principale che utilizza le funzioni `edit_distance` e `edit_distance_dyn`. Richiede come parametri 2 stringhe che verranno confrontate con le funzioni sopracitate.
* `edit_distance_tests` e' la suite di unit tests.
* `dictionary_words` e' il programma che stampa per ogni parola del file `correctme.txt` tutte le parole con edit distance minimo da `dictionary.txt`. Richiede come parametri il filepath di `correctme` e quello di `dictionary`.


Per lanciare l'esecuzione degli eseguibili e' necessario seguire i seguenti passaggi:
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 2), successivamente spostarsi all'interno della directory `bin`.
2. Eseguire il comando `./NOME_ESEGUIBILE` dove NOME_ESEGUIBILE e' il nome di uno dei 3 files eseguibili.
