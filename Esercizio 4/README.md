# Relazione
## Performance e analisi algoritmica
### Labeled Graph

La classe LabeledGraph rappresenta un grafo ottimizzato per dati sparsi con archi o spigoli etichettati. La distinzione tra archi e spigoli è necessaria sicché il grafo può essere orientato o meno (la differenza, come indicato nell'assegnazione del progetto, a livello implementativo è minima). La relazioni tra i vertici sono memorizzate in liste di adiacenza, implementate tramite l'utilizzo di HashMaps. L'utilizzo di queste particolari strutture dati permette una complessità temporale ammortizzabile ad $`\mathcal{O}(1)`$ (con $`\mathcal{O}(\log{}n)`$ nel caso temporalmente peggiore) per l'accesso in scrittura e lettura. Segue l'analisi temporale caso per caso dei metodi richiesti:

 * **LabeledGraph** - Creazione di un grafo vuoto
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: nel costruttore vengono inizializzate alcune variabili di classe e istanziate le strutture dati necessarie al funzionamento della classe.
 * **addVertex** - Aggiunta di un nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: Il nodo viene aggiunto alla lista di vertici. Essendo anch'essa implementata con un HashMap l'inserimento ha complessità $`\mathcal{O}(1)`$.
 * **addEdge** - Aggiunta di un arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: L'archo/spigolo viene aggiunto alle liste di adiacenza dei corrispettivi vertici. Essendo esse implementate con un HashMap l'inserimento ha complessità $`\mathcal{O}(1)`$.
 * **isDirected** - Verifica se il grafo è diretto
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: La proprietà di essere del diretto del grafo è rappresentata dal valore booleano isDirected, e si tratta quindi di restituire un semplice valore di tipo primitivo.
 * **containsVertex** - Verifica se il grafo contiene un dato nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$
    * Descrizione implementativa: Essendo la lista di vertici implementata tramite un HashMap l'accesso ha complessità $`\mathcal{O}(1)`$.
 * **containsEdge** - Verifica se il grafo contiene un dato arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso
    * Descrizione implementativa: Essendo le liste di adiacenza dei corrispettivi vertici (esplicitati negli argomenti del metodo) implementate con Hashmap, l'accesso ha complessità $`\mathcal{O}(1)`$.
 * **removeNode** - Cancellazione di un nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa:
 * **removeEdge** - Cancellazione di un arco
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso
    * Descrizione implementativa:
 * **getVerticesSize** - Determinazione del numero di nodi
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Complessità garantità: $`\mathcal{O}(1)`$
    * Descrizione implementativa:
 * **getEdgesSize** - Determinazione del numero di archi
    * Complessità richiesta: $`\mathcal{O}(n)`$
    * Complessità garantità: $`\mathcal{O}(1)`$
    * Descrizione implementativa:
 * **getSet** - Recupero dei nodi del grafo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa: CONVERSIONE A ARRAYLIST
 * **getEdges** - Recupero degli archi del grafo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Descrizione implementativa:
 * **getAdjacentVertices** - Recupero nodi adiacenti di un dato nodo
    * Complessità richiesta e garantita: $`\mathcal{O}(n)`$
    * Complessità garantità: $`\mathcal{O}(n)`$
    * Descrizione implementativa:
 * **getLabelByVertices** - Recupero etichetta associata a una coppia di nodi
    * Complessità richiesta e garantita: $`\mathcal{O}(1)`$ quando il grafo è veramente sparso.
    * Descrizione implementativa:

### Algoritmo di Kruskal

I performance test si sono basati sul file italian_dist_graph.csv messo a disposizione dal docente, ed eseguiti su un laptop di media potenza (le misure sono espresse in millisecondi):

| N° test | Media | Dev std |
|:-------:|:-----:|:-------:|
| 10      | 69859 |  2552   |
