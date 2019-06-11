# Relazione sul secondo Esercizio

## Introduzione
Questa relazione si pone l'obiettivo di discutere le scelte implementative per la realizzazione e l'ottimizzazione (in termini di complessita temporale) dell'esercizio 2.
Saranno poi confrontati i risultati delle analisi effettuate sulle diverse scelte intraprese.

## Algoritmo e funzionamento
L'algoritmo puo' essere riassunto principalmente nel seguente pseudocodice:

```
L1 ← List()
L2 ← List()
carica parole di correctme in L1
carica parole di dictionary in L2

for i ← 0 to lenght(L1) do:
  min ← min_ed(L1[i])              ► appartiene a O(n) poiche' devo scorrere tutto L2
  print(L1[i])
  for j ← 0 to length(L2) do:
    if edit_distance_dyn(L1[i], L2[j]) = min_ed then
      print(L2[j])

```

Per il calcolo dell'edit distance minimo, la funzione termina in caso l'edit distance valga 0 (poiche non si puo piu' ottenere un edit distance minimo, smette di scorrere il file).  
Solamente con questa modifica si e' ottenuto un incremento di circa il **35%** (da 70 secondi a 45 circa) in termini di tempo di esecuzione. 

## Accuratezza
Nell'applicazione pratica il programma pecca di alcune di alcune funzioni quali:

- Differenziazione delle maiuscole-minuscole (case-sensitive), ciò evita la corretta selezione di alcune parole.
	es. Mi => ai    (siccome il codice ascii del carattere 'M' e diverso da 'm' li riconosce come diversi e quindi
    aggiunge operazioni di rimozione/inserimento carattere)
    
- Mancata selezione della parola più adeguata, il programma non può scegliere (oltre al parametro intero edit_distance)
  la parola con significato più adeguato al contesto, ma solamente l'insieme di parole del dizionario il cui edit_distance è minore.
  
	es. **made** → **made**. Non viene selezionata la parola *Madre*, poiche' hanno tra loro un edit distance maggiore. (1 > 0 in questo specifico caso)

In linea generale l'algoritmo si e' pero' dimostrato abbastanza accurato, riuscendo a proporre tra l'insieme di parole la parola semanticamente corretta ben **46** volte su **49** parole totali.  

## Miglioramenti
Per migliorare l'accuratezza dell'algoritmo (con un conseguente trade-off in efficienza) si potrebbe proporre di aggiungere un valore di `offset`, in modo da selezionare anche le parole con un edit distance compreso tra `min_ed` e `min_ed + OFFSET`.  
In questo modo si eliminerebbero i casi citati nell'esempio precedente, e, in linea teorica, si raggiuggerebbe l'accuratezza del 100% dell'algoritmo (49/49 parole) in quanto e' stato osservato che tutti i casi di missmatch della parola sono appunto della tipologia di quelli dell'esempio.   
In questo specifico caso, si e' pero' deciso di dare piu' importanza all'efficienza poiche' non era nei fini dell'esercizio di estrarre la parola piu' semanticamente corretta, ma solamente di proporre una lista di parole il cui edit distance fosse minimo.  
Un'altra possibile soluzione consiste nel rimuovere le parole problematiche presenti nel dizionario, ad esempio **made**.

Per poter ottenere un drastico aumento delle prestazioni in termini di tempo, e' possibile anche utilizzare la programmazione concorrente, sfruttando i **thread** oppure interi **processi**.  
Creando un thread (oppure un processo) per ogni parola del file `correctme`, la ricerca del minimo e la selezione delle parole con l'edit distance medesimo potra' essere eseguita in parallelo.

## Test ed esecuzione
Di seguito saranno riportate delle tabelle con i test effettuati e i loro relativi tempi di esecuzione.  
I test sono stati effettuati su diversi laptop e computer desktop, con un range prestazionale da medio/bassa potenza ad alta potenza su sistema operativo Linux.


<table>
    <thead>
        <tr>
            <th>Macchina</th>
            <th>Numero test</th>
            <th>Tempo d'esecuzione</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan=4>PC Desktop</td>
            <td>1</td>
            <td>53.331547</td>
        <tr>
            <td>2</td>
            <td>53.331547</td>
        <tr>
            <td>3</td>
            <td>53.331547</td>
        <tr>
            <td>4</td>
            <td>53.331547</td>
        <tr>
            <td rowspan=4>Laptop media/bassa<br>potenza</td>
            <td>1</td>
            <td>49.944431</td>
        <tr>
            <td>2</td>
            <td>50.538304</td>
        <tr>
            <td>3</td>
            <td>52.910820</td>
        <tr>
            <td>4</td>
            <td>47.223654</td>
        <tr>
            <td rowspan=4>Laptop media/alta<br>potenza</td>
            <td>1</td>
            <td>41.593496</td>
        <tr>
            <td>2</td>
            <td>39.510722</td>
        <tr>
            <td>3</td>
            <td>38.897615</td>
        <tr>
            <td>4</td>
            <td>43.563783</td>
        </tr>
    </tbody>
    
</table>
