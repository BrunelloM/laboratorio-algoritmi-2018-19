package kruskalAlgorithm;

import graph.LabeledEdge;
import graph.LabeledGraph;
import graph.Vertex;
import unionfindset.UnionFind;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;

public class KruskalAlgorithm<T, U extends Double> {


  /**
   * The algorithm has been developed according on the one expressed on the course slieds with the following metacode:
   * <p>
   * MST_Kruskal(G)
   * A ← ∅
   * for ∀v ∈ V do
   * Make_set(v)
   * ordina gli archi in ordine non decrescente di peso
   * for ∀(u,v) ∈ E nell’ordine do
   * if Find(u) != Find(v) then
   * A ← A ∪ (u,v)
   * Union(u,v)
   *
   * @param graph       the graph onto which the MST will be computer
   * @param startVertex the starting vertex onto which the MST will be computed
   * @return the MST corresponding to the given graph
   */

  public LabeledGraph<T, Double> execute(LabeledGraph<T, Double> graph, Vertex<T> startVertex) {

    if (!graph.isWeighted())
      throw new IllegalStateException("The Kruskal Algorithm is meant to be used on weighted data structures");

    HashMap<T, T> verticesList = new HashMap<T, T>();
    LabeledEdgeComparator labeledEdgeComparator = new LabeledEdgeComparator();

    UnionFind<Vertex<T>> unionFind = new UnionFind<Vertex<T>>();

    LabeledGraph<T, Double> minimumSpanningTree = new LabeledGraph<>(); // 1. A ← ∅
    minimumSpanningTree.setIsWeighted(true);

    ArrayList<LabeledEdge<T, Double>> edgesList = new ArrayList<>(graph.getEdges());
    edgesList.sort(labeledEdgeComparator); // 4. ordina gli archi in ordine non decrescente di peso

    for (Vertex<T> vertex : graph.getVertices()) { // 2. for ∀v ∈ V do

      unionFind.makeSet(vertex); // 3. Make_set(v)

      for (LabeledEdge<T, Double> edge : edgesList) {
        if (edge.getYVertex().equals(vertex)) { // for ∀(u,v) ∈ E nell’ordine do

          if (unionFind.find(edge.getXVertex()) != null &&
              unionFind.find(edge.getYVertex()) != null &&
              unionFind.find(edge.getXVertex()) != unionFind.find(edge.getYVertex())) { // 6. if Find(u) != Find(v) then

            minimumSpanningTree.addVertex(edge.getXVertex().getVertexLabel());
            minimumSpanningTree.addVertex(edge.getYVertex().getVertexLabel());
            minimumSpanningTree.addEdge(edge.getLabel(), edge.getXVertex().getVertexLabel(), edge.getYVertex().getVertexLabel()); // 7. A ← A ∪ (u,v)

            unionFind.union(edge.getXVertex(), edge.getYVertex()); // 8. Union(u,v)

          }
        }
      }
    }

    return minimumSpanningTree;
  }


  public class LabeledEdgeComparator implements Comparator<LabeledEdge<T, Double>> {
    @Override
    public int compare(LabeledEdge<T, Double> aEdge, LabeledEdge<T, Double> bEdge) {
      return aEdge.getLabel().compareTo(bEdge.getLabel());
    }
  }
}