package test;

import graph.LabeledGraph;
import org.junit.Before;
import org.junit.Test;

public class GraphTesting {

  private LabeledGraph<String, Double> graph;

  @Before
  public void createGraph() {
    graph = new LabeledGraph<>();
  }

  @Test
  public void testIsWeighted_true() {
    graph.setIsWeighted(true);
    assertTrue(graph.isWeighted());
  }

}
