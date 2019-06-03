package kruskalAlgorithmUsage;


import graph.LabeledGraph;
import graph.Vertex;
import kruskalAlgorithm.KruskalAlgorithm;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

/**
 * @author Brunello Matteo, Caresio Lorenzo
 */
public class KruskalAlgorithmUsage {

  public static void main(String[] args) {


    if (args.length < 1) {
      System.out.println("Invalid list of arguments\n");
    } else {

      LabeledGraph<String, Double> graph = new LabeledGraph<>();
      HashMap<String, Boolean> insertedVerticesList = new HashMap<String, Boolean>(); // Used in order to know if a given vertex is already part of the graph

      graph.setIsWeighted(true);

      // Vertices and corresponding edges are parsed from the csv file
      try {
        FileReader fr = new FileReader(args[0]);
        BufferedReader br = new BufferedReader(fr);
        String currentFileLine;

        while ((currentFileLine = br.readLine()) != null) {
          String[] lineContents = currentFileLine.split(","); // In CSV values are separated by commas

          // A vertex has to be inserted in the graph if it isn't part of it yet
          if (insertedVerticesList.get(lineContents[0]) == null) {
            graph.addVertex(lineContents[0]);
            insertedVerticesList.put(lineContents[0], Boolean.TRUE);
          }

          // A vertex has to be inserted in the graph if it isn't part of it yet
          if (insertedVerticesList.get(lineContents[1]) == null) {
            graph.addVertex(lineContents[1]);
            insertedVerticesList.put(lineContents[1], Boolean.TRUE);
          }

          graph.addVertex(lineContents[1]);
          graph.addEdge(Double.parseDouble(lineContents[2]), lineContents[0], lineContents[1]);
        }
      } catch (FileNotFoundException e) {
        System.err.println("The dataset file doesn't exists");
        e.printStackTrace();
      } catch (IOException e) {
        System.err.println("An error has occurred while trying to parse the dataset");
        e.printStackTrace();
      }

      // Basing on the Kruskal Algorithm definition, the initial vertex has to be randomly picked
      Random random = new Random();
      ArrayList<Vertex<String>> vertices = graph.getVertices();
      Vertex<String> startVertex = vertices.get(random.nextInt(vertices.size()));

      KruskalAlgorithm kruskalAlgorithm = new KruskalAlgorithm();
      long timestampBeforeExecution = System.currentTimeMillis();
      LabeledGraph<String, Double> graphMST = kruskalAlgorithm.execute(graph, startVertex);
      long timestampAfterExecution = System.currentTimeMillis();

      System.out.println("Original Graph: \n\tNodes: " + graph.getVertices().size() + "\n\tEdges: " + graph.getEdgesSize()); // +"\n\tWeight: " + String.format("%.2f", graph.getWeight()));

      System.out.println("MST Graph: \n\tNodes: " + graphMST.getVertices().size() + "\n\tEdges: " + graphMST.getEdgesSize()); // + "\n\tWeight: " + String.format("%.2f", graphMST.getWeight()));

      System.out.println("\n\nExecution ended in " + (timestampAfterExecution - timestampBeforeExecution) + " milliseconds");

    }
  }
}