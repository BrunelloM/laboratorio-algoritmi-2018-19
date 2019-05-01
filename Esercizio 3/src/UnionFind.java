import java.util.ArrayList;
import java.util.Comparator;
/*
** @author Matteo Brunello
** @param <T>: Type of the set elements
*/
public class UnionFind<T> {
    private Comparator<? super T> comparator = null;
    ArrayList<Set<T>> setsCollection = null;

    public UnionFind() {
        this.setsCollection = new ArrayList<>();
    }

    public UnionFind(Comparator<? super T> comparator) throws SetException {
        if(comparator == null) throw new SetException("Comparator parameter cannot be null value");

        this.comparator = comparator;
        this.setsCollection = new ArrayList<>();
    }

    public void makeSet(T x) throws SetException {
        // Check if the value is already present in one of the sets
        if(find(x) != null) throw new SetException("Element already present in one set");
        Set<T> newSet = new Set<T>(this.comparator);
        newSet.addElement(x);
        this.setsCollection.add(newSet);
    }

    public void union(T x, T y) throws SetException {
        if(find(x) == null || find(y) == null) throw new SetException("One of the 2 elements are not present in any sets");
        Set<T> Sx = getSet(x);
        Set<T> Sy = getSet(y);

        Sx.merge(Sy);   // Merge the two sets
        setsCollection.remove(Sy);  // Remove the non merged set
    }

    public T find(T x) {
        for(Set<T> s : setsCollection) {
            if(s.hasElement(x))
                return s.getRoot();
        }
        return null;
    }

    private Set<T> getSet(T x) {
        for(Set<T> s : setsCollection) {
            if(s.hasElement(x))
                return s;
        }
        return null;
    }

    public void print() {
        for(Set<T> s : setsCollection)
            s.print();
    }

}
