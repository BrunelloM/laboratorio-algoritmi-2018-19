# Esercizio 1 (Implementazione di una struttura dati lista):

## Compilazione (tramite script):
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 1).
2. Dare i permessi necessari all'esecuzione dello script `build.sh` tramite il comando `chmod +777 ./build.sh`.
3. Eseguire `./build.sh`.

## Compilazione (tramite utility make):
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 1).
2. Eseguire il comando `mkdir -p ./bin ./obj`, il quale crea le cartelle necessarie alla compilazione solo in caso esse non siano gia' presenti.
3. Lanciare il comando `make all`.

## Esecuzione:
Durante il processo di compilazione verranno creati 4 files eseguibili.
Gli eseguibili contrassegnati con la parola `array` prima del nome, faranno riferimento all'implementazione della lista tramite array dinamici, mentre quelli con la parola `node` faranno riferimento a quella tramite record collegati.

Per lanciare l'esecuzione degli eseguibili e' necessario seguire i seguenti passaggi:
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 1), successivamente spostarsi all'interno della directory `bin`.
2. Eseguire il comando `./NOME_ESEGUIBILE` dove NOME_ESEGUIBILE e' il nome di uno dei 4 files eseguibili.
