# Relazione
## Compilazione ed esecuzione
### Compilazione
1. Posizionarsi tramite terminale all'interno della directory corrente (Esercizio 4)
2. Dare i permessi necessari all'esecuzione dello script `build.sh` tramite il comando `chmod +777 ./build.sh`
3. Eseguire `./build.sh`

Una volta eseguito lo script i file necessari all'esecuzione dell'esercizio saranno disponibili nella cartella `out` (saranno anche resi disponibili gli eseguibili dei test).

### Esecuzione

Come anticipato per l'esecuzione dei file sarà necessario posizionarsi all'interno della cartella `out`. Per l'esecuzione dell'esercizio si dovrà quindi indicare la posizione relativa (alla cartella contenente l'eseguibile) del dataset su cui si vorrà calcolare il MST tramite l'Argoritmo di Kruskal. Segue una possibile formulazione del comando:

   ```
   java kruskalAlgorithmUsage.KruskalAlgorithmUsage ../Resources/italian_dist_graph.csv
   ```

Mentre per l'esecuzione dei test sarà necessario indicare il path del file `junit4.jar` e di `hamcrest-core-1.3.jar`. Segue una possibile formulazione del comando:
```
java -cp ".:/usr/share/java/junit4.jar:/usr/share/java/hamcrest-core-1.3.jar:" test.GraphTestingRunner
```

## Analisi algoritmica e performance
### Labeled Graph

La classe LabeledGraph rappresenta un grafo ottimizzato per dati sparsi con archi o spigoli etichettati. La distinzione tra archi e spigoli è necessaria sicché il grafo può essere orientato o meno (la differenza, come indicato nell'assegnazione del progetto, a livello implementativo è minima). La relazioni tra i vertici sono memorizzate in liste di adiacenza, implementate tramite l'utilizzo di HashMaps. L'utilizzo di queste particolari strutture dati permette una complessità temporale ammortizzabile ad $`\mathcal{O}(1)`$ (con $`\mathcal{O}(\log{}n)`$ nel caso temporalmente peggiore) per l'accesso in scrittura e lettura. Segue l'analisi temporale caso per caso dei metodi richiesti:

 * **LabeledGraph** - Creazione di un grafo vuoto
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: nel costruttore vengono inizializzate alcune variabili di classe e istanziate le strutture dati necessarie al funzionamento della classe.
 * **addVertex** - Aggiunta di un nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: il nodo viene aggiunto alla lista di vertici. Essendo essa implementata con un HashMap l'inserimento ha complessità $`\mathcal{O}(1)`$.
 * **addEdge** - Aggiunta di un arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: l'archo/spigolo viene aggiunto alle liste di adiacenza dei corrispettivi vertici. Essendo esse implementate con un HashMap l'inserimento ha complessità $`\mathcal{O}(1)`$.
 * **isDirected** - Verifica se il grafo è diretto
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: la proprietà di essere del diretto del grafo è rappresentata dal valore booleano isDirected, e si tratta quindi di restituire un semplice valore di tipo primitivo.
 * **containsVertex** - Verifica se il grafo contiene un dato nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: essendo la lista di vertici implementata tramite un HashMap l'accesso ha complessità $`\mathcal{O}(1)`$.
 * **containsEdge** - Verifica se il grafo contiene un dato arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso
    * Descrizione implementativa: essendo le liste di adiacenza dei corrispettivi vertici (esplicitati negli argomenti del metodo) implementate con Hashmap, l'accesso ha complessità $`\mathcal{O}(1)`$.
 * **removeNode** - Cancellazione di un nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa: il nodo viene rimosso dalla lista dei vertici. Essendo essa implementata con un HashMap la rimozione ha complessità $`\mathcal{O}(1)`$. In caso il grafo fosse orientato il vertice va inoltre rimosso dalle liste di adiacenza dei vertici a lui correlati, rendendo così la complessità $`\mathcal{O}(k)`$.
 * **removeEdge** - Cancellazione di un arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso
    * Descrizione implementativa: essendo le liste di adiacenza dei corrispettivi vertici (esplicitati negli argomenti del metodo) implementate con Hashmap, la rimozione ha complessità $`\mathcal{O}(1)`$.
 * **getVerticesSize** - Determinazione del numero di nodi
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Complessità garantità: $`\mathcal{O}(1)`$
    * Descrizione implementativa: essendo la lista di vertici implementata tramite un HashMap l'accesso alla sua dimensione ha complessità $`\mathcal{O}(1)`$. (cfr JAVADOC)
 * **getEdgesSize** - Determinazione del numero di archi
    * Complessità richiesta: $`\mathcal{O}(n)`$
    * Complessità garantità: $`\mathcal{O}(1)`$
    * Descrizione implementativa: non essendo presente una lista degli archi (sono memorizzati tramite le varie liste di adiacenza) si è ritenuto corretto memorizzare il numero di archi in una variabile numerica apposita (*edgesNumber*). Si tratta quindi di restituire un semplice valore di tipo primitivo.
 * **getVertices** - Recupero dei nodi del grafo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa: i vertici contenuti nella lista dei nodi vengono inseriti in un ArrayList, operazione con complessità pari a $`\mathcal{O}(n)`$.
 * **getEdges** - Recupero degli archi del grafo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa: gli archi vengono recuperati tramite l'iterazione delle liste di adiacenza. Essendo esse implementate con HashMap la complessità è $`\mathcal{O}(n)`$.
 * **getAdjacentVertices** - Recupero nodi adiacenti di un dato nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa: i nodi contenuti nella lista di adiacenza nella lista di un dato vengono restituiti come un ArrayList. Mentre l'accesso alla lista di adiacenza ha complessità $`\mathcal{O}(1)`$ l'accesso e l'aggiuntà dei nodi correlati ha complessità pari a $`\mathcal{O}(n)`$.
 * **getLabelByVertices** - Recupero etichetta associata a una coppia di nodi
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso.
    * Descrizione implementativa: la label è un attributo di un dato arco/spigolo, essendo quest'ultimo memorizzato nelle liste di adiacenza uno dei vertici indicati per argomento non si tratta d'altro che di un accesso ad una HashMap (con complessità pari a $`\mathcal{O}(n)`$)

### Algoritmo di Kruskal

I performance test si sono basati sul file italian_dist_graph.csv messo a disposizione dal docente, ed eseguiti su un laptop di media potenza (le misure sono espresse in millisecondi):

| N° test | Media | Dev std |
|:-------:|:-----:|:-------:|
| 10      | 311   |  29   |
