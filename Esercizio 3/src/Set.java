import java.util.ArrayList;
import java.util.Comparator;
import java.util.Arrays;
/*
** @author Matteo Brunello
** @param <T>: Type of the set elements
*/
public class Set<T> {
    ArrayList<T> elements = null;
    private Comparator<? super T> comparator = null;

    public Set(Comparator<? super T> comparator) throws SetException {
        //System.out.println("Comparator: " + comparator.toString());
        if(comparator == null) throw new SetException("Comparator parameter cannot be null value");

        this.elements = new ArrayList<>();
        this.comparator = comparator;
    }

    public void addElement(T newElement) {
        elements.add(newElement);
    }

    public boolean hasElement(T toCheck) {
        for(T element : elements) {
            if(comparator.compare(element, toCheck) == 0) {
                return true;
            }
        }
        return false;
    }

    public T getRoot() {
        return elements.get(0);
    }

    public void merge(Set<T> s) {
        this.elements.addAll(s.getElements());
    }

    public ArrayList<T> getElements() {
        return this.elements;
    }

    public void print() {
        System.out.println(Arrays.toString(this.elements.toArray()));
    }
}
