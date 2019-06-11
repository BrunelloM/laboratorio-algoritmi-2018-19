# Relazione
## Compilazione ed esecuzione
### Compilazione
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 3)
2. Dare i permessi necessari all'esecuzione dello script `build.sh` tramite il comando `chmod +777 ./build.sh`
3. Eseguire `./build.sh`
### Esecuzione

Trattandosi esclusivamente di una struttura dati non è presente un vero e proprio eseguibile (sarà utilizzata nell'Esercizio 4), sono stati però implementati dei test per assicurarsi della sua corretta implementazione. Posizionaticisi nella cartella `out` sarà necessario indicare il path del file `junit4.jar` e di `hamcrest-core-1.3.jar` per eseguire i test. Segue una possibile formulazione del comando:
```
java -cp ".:/usr/share/java/junit4.jar:/usr/share/java/hamcrest-core-1.3.jar:" test.GraphTestingRunner
```
