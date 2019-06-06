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
