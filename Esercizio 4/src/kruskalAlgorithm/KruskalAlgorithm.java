package kruskalAlgorithm;

import graph.LabeledEdge;
import graph.LabeledGraph;
import graph.Vertex;
import unionfindset.SetException;
import unionfindset.UnionFind;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class KruskalAlgorithm<T, U extends Comparable> {


  /*
 MST_Kruskal(G)
  A ← ∅
  for ∀v ∈ V do
    Make_set(v)
    ordina gli archi in ordine non decrescente di peso
    for ∀(u,v) ∈ E nell’ordine do
      if Find(u) != Find(v) then
        A ← A ∪ (u,v)
        Union(u,v)
  */

  public LabeledGraph<T, U> execute(LabeledGraph<T, U> graph, Vertex<T> startVertex) {

    if (!graph.isWeighted())
      throw new IllegalStateException("The Kruskal Algorithm is meant to be used on weighted data structures");


    HashMap<T, T> verticesList = new HashMap<T, T>();
    ArrayList<LabeledEdge<T, U>> edgesList = new ArrayList<>();
    LabeledEdgeComparator labeledEdgeComparator = new LabeledEdgeComparator();

    UnionFind unionFind = new UnionFind();

    LabeledGraph<T, U> minimumSpanningTree = new LabeledGraph<>(); // 1. A ← ∅
    minimumSpanningTree.setIsWeighted(true);

    for (Vertex<T> vertex : graph.getVertices()) { // 2. for ∀v ∈ V do

      ArrayList<Vertex<T>> singletonSet = new ArrayList<>();
      singletonSet.add(vertex);
      unionFind.makeSet(singletonSet); // 3. Make_set(v)

      Collections.sort(edgesList, labeledEdgeComparator); // 4. ordina gli archi in ordine non decrescente di peso

      for (LabeledEdge<T, U> edge : edgesList) {
        try {
          if (unionFind.find(edge.getXVertex()) != unionFind.find(edge.getYVertex())) { // 5. if Find(u) != Find(v) then
            minimumSpanningTree.addVertex(edge.getXVertex().getVertexLabel());
            minimumSpanningTree.addVertex(edge.getXVertex().getVertexLabel());
            minimumSpanningTree.addEdge(edge.getLabel(), edge.getXVertex().getVertexLabel(), edge.getYVertex().getVertexLabel()); // 6. A ← A ∪ (u,v)
            unionFind.union(edge.getXVertex(), edge.getYVertex()); // 7. Union(u,v)
          }
        } catch (SetException e) {
          e.printStackTrace();
        }
      }
    }

    return minimumSpanningTree;
  }


  public class LabeledEdgeComparator<U extends Comparable> implements Comparator<U> {
    @Override
    public int compare(U edgeWeight, U secondEdgeWeight) {
      return edgeWeight.compareTo(secondEdgeWeight);
    }
  }
}