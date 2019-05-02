package unionfindset;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;
/*
** @author Matteo Brunello
** @param <T>: Type of the set elements
*/
public class UnionFind<T> {
    ArrayList<ArrayList<T>> setsCollection = null;

    public UnionFind() {
        this.setsCollection = new ArrayList<>();
    }

    public void makeSet(T x) throws SetException {
        // Check if the value is already present in one of the sets
        if(find(x) != null) throw new SetException("Element already present in one set");
        ArrayList<T> newSet = new ArrayList<>();
        newSet.add(x);
        this.setsCollection.add(newSet);
    }

    public void union(T x, T y) throws SetException {
        if(find(x) == null || find(y) == null) throw new SetException("One of the 2 elements are not present in any sets");

        ArrayList<T> Sx = getSet(x);
        ArrayList<T> Sy = getSet(y);

        if(Sx != Sy) {
            Sx.addAll(Sy);              // Merge Sx with Sy
            setsCollection.remove(Sy);  // Remove the non merged set
        }

    }

    public T find(T x) {
        for(ArrayList<T> curSet : setsCollection) {
            if(curSet.contains(x))
                return curSet.get(0);
        }
        return null;
    }

    private ArrayList<T> getSet(T x) {
        for(ArrayList<T> curSet : setsCollection) {
            if(curSet.contains(x))
                return curSet;
        }
        return null;
    }

    public void print() {
        for(ArrayList<T> curSet : setsCollection) {
            System.out.println(Arrays.toString(curSet.toArray()));
        }
    }

}
