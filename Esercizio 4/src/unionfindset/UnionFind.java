package unionfindset;

import java.util.HashMap;

/**
 * @param <T>: Type of the set elements
 * @author Brunello Matteo, Caresio Lorenzo
 */
public class UnionFind<T> {

  private HashMap<T, T> parenthoodList;

  public UnionFind() {
    parenthoodList = new HashMap<>();
  }

  public void makeSet(T element) {
    parenthoodList.put(element, element);
  }

  public T find(T element) {

    T parent = parenthoodList.get(element);
    while (parent != parenthoodList.get(parent)) {
      parent = parenthoodList.get(parent);
    }

    T aElement = null;
    T father = parenthoodList.get(element);

    while (father != parenthoodList.get(father)) {
      aElement = parenthoodList.get(father);
      parenthoodList.put(father, parent);
      father = aElement;
    }

    parenthoodList.put(element, parent);
    return parent;
  }

  public void union(T aElement, T bElement) {

    T xElement = find(aElement);
    T yElement = find(bElement);

    if (xElement != yElement) {
      parenthoodList.put(xElement, yElement);
    }
  }

}
