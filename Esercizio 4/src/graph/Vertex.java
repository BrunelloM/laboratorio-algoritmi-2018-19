package graph;

import java.util.Objects;

/**
 * @param <T>: label type
 * @author Brunello Matteo, Caresio Lorenzo
 */
public class Vertex<T> {

  private T vertexLabel;

  /**
   * Constructor of the Vertex class.
   *
   * @param vertexLabel: the label of the vertex
   */
  public Vertex(T vertexLabel) {
    this.vertexLabel = vertexLabel;
  }

  /**
   * Getter of the vertex label.
   */
  public T getVertexLabel() {
    return vertexLabel;
  }

  /**
   * Setter for the vertex label.
   *
   * @param vertexLabel: the vertex label to set
   */
  public void setVertexLabel(T vertexLabel) {
    this.vertexLabel = vertexLabel;
  }

  /**
   * if the object exists but isn't the actual one, the two labels are
   * compared
   *
   * @param obj: the object to compare (presumably of type Vertex<T>)
   */
  @Override
  public boolean equals(Object obj) {

    if (this == obj) {
      return true;
    }

    if (!(obj instanceof Vertex<?>)) {
      return false;
    }

    Vertex<T> vertex = (Vertex<T>) obj;
    return vertexLabel.equals(vertex.vertexLabel);
  }


  @Override
  public String toString() {
    return vertexLabel.toString();
  }

}
