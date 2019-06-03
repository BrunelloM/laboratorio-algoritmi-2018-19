package unionfindset;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;

/*
 ** The {UnionFind} class represents a disjoint set data structure.
 ** It uses an array of indexes {parents[]} to keep track of parental relationships between elements.
 ** Actual elements are stored in an ArrayList called {elements}
 **
 ** @author Brunello Matteo, Caresio Lorenzo
 ** @param <T>: Type of the set elements
 */
public class UnionFind<T> {
  ArrayList<T> elements = null;
  int parents[] = null;

  public UnionFind() {
    elements = new ArrayList<>();
  }

  /*
   ** MakeSet method of the data structure.
   ** It creates as many disjoint sets as the parameter's set size which are all singletons (a set made up of only one element).
   **
   ** @param {ArrayList<T> set}: The ArrayList representing the input set
   */
  public void makeSet(ArrayList<T> set) {
    assert set != null;
    parents = new int[set.size()];
    for (int i = 0; i < set.size(); i++) {
      parents[i] = i;
      elements.add(set.get(i));
    }
  }

  /*
   ** It returns the root's value of a specified element by recurring down to the {parents} array of indexes
   ** and by updating their parent's value (path compression) on each iteration of the while cycle.
   ** Using this technique can optimize {find} time making it an O(m log n) [where m represents the operations] complexity algorithm.
   **
   ** @param {ArrayList<T> set}: The ArrayList representing the input set
   ** @returns {T root}: The value subset's root value.
   ** @throws {SetException}: When one of the elements is invalid (isn't present in any set)
   */
  public T find(T x) throws SetException {
    assert x != null;
    int index = elements.indexOf(x);
    if (index == -1) throw new SetException("element isn't present in the set: unable to find element");

    while (index != parents[index]) {
      parents[index] = parents[parents[index]];    // Path compression
      index = parents[index];
    }

    return elements.get(parents[index]);
  }

  /*
   ** Merges two sets that contains the element {x} and the element {y}
   ** It does nothing if the elements are already in the same set.
   **
   ** @param {T x}: The first element
   ** @param {T y}: The second element
   ** @throws {SetException}: When one of the elements is invalid (isn't present in any set)
   */
  public void union(T x, T y) throws SetException {
    assert x != null && y != null;
    int xIndex = elements.indexOf(find(x)); // Index radice di x
    int yIndex = elements.indexOf(find(y)); // Index radice di y

    if (xIndex == yIndex)                    // Elements are already present in the same set
      return;

    parents[xIndex] = yIndex;               // Tree merge
  }

  /*
   ** Prints parents array and their elements.
   */
  public void print() {
    for (int i = 0; i < elements.size(); i++) {
      System.out.println(Arrays.toString(parents));
    }
  }

}
