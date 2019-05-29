package graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Comparator;

/**
 * @param <T>: vertices label type
 * @param <U>: edges label type
 * @author Brunello Matteo, Caresio Lorenzo
 * <p>
 * <p>
 * The class has been developed according to the guidelines stated on the project assignment:
 * LabeledGraph: creazione di un grafo vuoto – O(1)
 * addVertex: aggiunta di un nodo – O(1)
 * addEdge: aggiunta di un arco – O(1)
 * isWeighted: verifica se il grafo è diretto – O(1)
 * findVertex: verifica se il grafo contiene un dato nodo – O(1)
 * ?
 * removeVertex: Cancellazione di un nodo – O(n)
 * removeEdge: Cancellazione di un arco – O(1) quando il grafo è veramente sparso
 * getVerticesNumber: Determinazione del numero di nodi – O(n)
 * getEdgesNumber: Determinazione del numero di archi – O(n)
 * getVertices: Recupero dei nodi del grafo – O(n)
 * ?
 * getAdjacentEdges: Recupero nodi adiacenti di un dato nodo – O(n)
 * ?
 *
 * To be added:
 * Recupero degli archi del grafo – O(n)
 * Verifica se il grafo contiene un dato arco – O(1) quando il grafo è veramente sparso
 * Recupero etichetta associata a una coppia di nodi – O(1) quando il grafo è veramente sparso.
 *
 */
public class LabeledGraph<T, U> {

  // The HashMap is used both to implement an Adjacency list and to implement an efficient way to directly access to an object
  private HashMap<Vertex<T>, ArrayList<LabeledEdge<T, U>>> adjacencyList;
  private HashMap<T, Vertex<T>> vertices;

  private int verticesNumber;
  private int edgesNumber;
  private boolean isWeighted;
  private boolean isDirected;

  public LabeledGraph() {

    verticesNumber = 0;
    edgesNumber = 0;
    isWeighted = false;
    isDirected = false;

    adjacencyList = new HashMap<>();
    vertices = new HashMap<>();
  }

  /**
   * Setter for the isWeighted variable.
   *
   * @param isWeighted: the value to set the variable to
   */
  public void setIsWeighted(boolean isWeighted) {
    this.isWeighted = isWeighted;
  }

  /**
   * Setter for the isDirected variable.
   *
   * @param isDirected: the value to set the variable to
   */
  public void setIsDirected(boolean isDirected) {
    this.isDirected = isDirected;
  }

  /**
   * Getter for the isWeighted variable.
   */
  public boolean isWeighted() {
    return isWeighted;
  }

  /**
   * Getter for the isDirected variable.
   */
  public boolean isDirected() {
    return isDirected;
  }

  /**
   * Returns the vertices list as an ArrayList
   */
  public ArrayList<Vertex<T>> getVertices() {
    ArrayList<Vertex<T>> verticesArrayList = new ArrayList<>();
    for (Vertex<T> vertex : vertices.values()) {
      verticesArrayList.add(vertex);
    }
    return verticesArrayList;
  }

  /**
   * Returns the number of vertices contained in the graph.
   */
  public int getVerticesNumber() {
    return verticesNumber;
  }

  /**
   * Returns the number of edges contained in the graph.
   */
  public int getEdgesNumber() {
    return isDirected ? edgesNumber : edgesNumber / 2;
  }

  /**
   * Returns the adjacent vertices to a given one. The adjacent vertecies are
   * obtained from the corresponding edges adjacency list.
   *
   * @param vertex: The vertex to use to get its adjacent vertices
   */
  public ArrayList<Vertex<T>> getAdjacentVertices(Vertex<T> vertex) {
    ArrayList<Vertex<T>> adjacentVertices = new ArrayList();
    for (LabeledEdge<T, U> labeledEdge : adjacencyList.get(vertex)) {
      adjacentVertices.add(labeledEdge.getYVertex());
    }
    return adjacentVertices;
  }

  /**
   * Returns the adjacent edges to a given vertex. They are obtained from the
   * corresponding edges adjacency list.
   *
   * @param vertex: the vertex to use to get its adjacent edges
   */
  public ArrayList<LabeledEdge<T, U>> getAdjacentEdges(Vertex<T> vertex) {
    return adjacencyList.get(vertex);
  }

  /**
   * Returns the vertex object corresponding to a given vertex label. Returns
   * null if the vertex isn't part of the graph.
   *
   * @param vertexLabel: the label of the vertex to find
   */
  public Vertex<T> findVertex(T vertexLabel) {
    return vertices.get(vertexLabel);
  }

  /**
   * Returns the vertex degree of a given vertex.
   *
   * @param vertex: the vertex to use to compute its degree
   */
  public int getVertexDegree(Vertex<T> vertex) {

    if (vertex != null) {
      int sum = adjacencyList.get(vertex).size();

      for (Vertex<T> xVertex : vertices.values()) {
        for (LabeledEdge<T, U> edge : adjacencyList.get(xVertex)) {
          if (!xVertex.equals(vertex) && edge.getYVertex().equals(vertex)) {
            sum++;
          }
        }
      }

      return sum;
    } else {
      throw new IllegalStateException("The vertex has to be a valid vertex.");
    }
  }

  /**
   * Returns the incidents edges to a given vertex.
   *
   * @param vertex: the vertex of which the incident edges has to be computed
   */
  public ArrayList<LabeledEdge<T, U>> incidentEdges(Vertex<T> vertex) {

    if (vertex != null) {
      ArrayList<LabeledEdge<T, U>> incidentEdges = new ArrayList<LabeledEdge<T, U>>();
      incidentEdges.addAll(adjacencyList.get(vertex));

      for (Vertex<T> aVertex : vertices.values()) {
        for (LabeledEdge<T, U> edge : adjacencyList.get(aVertex)) {
          if (!aVertex.equals(vertex) && edge.getYVertex().equals(vertex)) {
            incidentEdges.add(edge);
          }
        }
      }

      return incidentEdges;
    } else {
      throw new IllegalStateException("The vertex has to be a valid vertex.");
    }
  }

  /**
   * Computes if the two given vertices are adjacent to eachothers.
   *
   * @param aVertex: the first vertex
   * @param bVertex: the second vertex
   */
  public boolean adjacent(Vertex<T> aVertex, Vertex<T> bVertex) {

    if (aVertex != null && bVertex != null) {

      for (LabeledEdge<T, U> aEdge : adjacencyList.get(aVertex)) {
        if (aEdge.getYVertex().equals(bVertex)) {
          return true;
        }
      }

      for (LabeledEdge<T, U> bEdge : adjacencyList.get(bVertex)) {
        if (bEdge.getYVertex().equals(aVertex)) {
          return true;
        }
      }

      return false;
    } else {
      throw new IllegalStateException("A vertex or both aren't not valid.");
    }
  }

  /**
   * Adds a vertex to the graph using its label. If a vertex with the same
   * label is already part of the graph, returns false
   *
   * @param: vertexLabel: the label of the vertex to add to the graph
   */
  public boolean addVertex(T vertexLabel) {

    if (findVertex(vertexLabel) == null) {

      Vertex<T> newVertex = new Vertex(vertexLabel);
      vertices.put(vertexLabel, newVertex);
      verticesNumber++;

      ArrayList<LabeledEdge<T, U>> adjacentsToThisVertex = new ArrayList<LabeledEdge<T, U>>();
      adjacencyList.put(newVertex, adjacentsToThisVertex);

      return true;
    } else {
      return false;
    }
  }

  /**
   * Adds an edge to the graph using its label and its two corresponding
   * vertices. If the vertices aren't already part of the graph, returns false
   *
   * @param edgeLabel: the label of the edge to be added to the graph
   * @param xVertex:   the first vertex
   * @param yVertex:   the second vertex
   */
  public boolean addEdge(U edgeLabel, Vertex<T> xVertex, Vertex<T> yVertex) {

    if (xVertex != null && yVertex != null) {

      LabeledEdge<T, U> xToYEdge = new LabeledEdge<T, U>(edgeLabel, xVertex, yVertex);
      ArrayList<LabeledEdge<T, U>> adjacentsToXVertex = adjacencyList.get(xVertex);
      adjacentsToXVertex.add(xToYEdge);
      edgesNumber++;

      if (!isDirected) {
        LabeledEdge<T, U> yToXEdge = new LabeledEdge<T, U>(edgeLabel, yVertex, xVertex);
        ArrayList<LabeledEdge<T, U>> adjacentsToYVertex = adjacencyList.get(yVertex);
        adjacentsToYVertex.add(yToXEdge);
        edgesNumber++;
      }

      return true;
    } else {
      return false;
    }
  }

  /**
   * Removes a vertex from the graph. If the vertex isn't part of the graph,
   * returns false
   *
   * @param vertexLabel: the label of the vertex to remove
   */
  public boolean removeVertex(T vertexLabel) {

    Vertex<T> vertex = findVertex(vertexLabel);

    if (vertex == null) {
      return false;
    }

    vertices.remove(vertexLabel);
    verticesNumber--;

    edgesNumber = edgesNumber - adjacencyList.get(vertex).size();
    adjacencyList.remove(vertex);

    // Every edge related to the vertex will be deleted
    for (Vertex<T> aVertex : vertices.values()) {
      ArrayList<LabeledEdge<T, U>> edgesToBeRemoved = new ArrayList<LabeledEdge<T, U>>();

      for (LabeledEdge<T, U> edge : adjacencyList.get(aVertex)) {
        if (edge.getYVertex().equals(vertex)) {
          edgesToBeRemoved.add(edge);
        }
      }

      edgesNumber = edgesNumber - edgesToBeRemoved.size();
      adjacencyList.get(aVertex).removeAll(edgesToBeRemoved);
    }

    return true;
  }

  /**
   * Removes an edge from the graph using the two given vertices.
   *
   * @param xVertex: the first vertex
   * @param yVertex: the second vertex
   */
  public boolean removeEdge(Vertex<T> xVertex, Vertex<T> yVertex) {

    for (LabeledEdge<T, U> edge : adjacencyList.get(xVertex)) {
      if (edge.getYVertex().equals(yVertex)) {
        adjacencyList.get(xVertex).remove(edge);
        edgesNumber--;
        return true;
      }
    }

    return false;
  }

  /**
   * Returns the total weight of the graph. Since an undirected graph has
   * twice the edges, its weight has to be divided by two. (cfr. Mr. Magro's
   * suggestions on the slides)
   */
  public double getWeight() {
    if (isWeighted) {
      double graphWeight = 0;

      for (Vertex<T> vertex : vertices.values()) {
        for (LabeledEdge<T, U> edge : adjacencyList.get(vertex)) {
          graphWeight += edge.getWeight();
        }
      }

      return isDirected ? graphWeight : graphWeight / 2;
    } else {
      throw new UnsupportedOperationException("The graph isn't weighted.");
    }
  }

  /**
   * Prints the graph to the command line.
   */
  public void printGraph() {
    for (Vertex<T> vertex : vertices.values()) {
      System.out.println("(" + vertex + ")");
      for (LabeledEdge<T, U> edge : adjacencyList.get(vertex)) {
        System.out.println("\t" + edge);
      }
    }
  }

}
