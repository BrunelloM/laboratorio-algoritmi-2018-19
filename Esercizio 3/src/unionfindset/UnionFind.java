import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;
/*
** @author Matteo Brunello
** @param <T>: Type of the set elements
*/
public class UnionFind<T> {
    ArrayList<T> elements = null;
    int parents[] = null;

    public UnionFind() {
        elements = new ArrayList<>();
    }

    public void makeSet(ArrayList<T> set) {
        parents = new T[set.size()];
        for(int i = 0; i < set.size(); i++) {
            parents[i] = i;
            elements.add(set.get(i));
        }
    }

    public void makeSet(T... set) {

    }

    public T find(T x) {
        int index = elements.indexOf(x);

        if(index == -1) throws new SetException();
    }

    public void union(T x, T y) {

    }


    public void print() {
        for(Element elem : elements) {
            System.out.println(elem + "->" + elem.getParent());
        }
    }

}
