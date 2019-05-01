import java.util.Comparator;

public class IntegerComparator implements Comparator<Integer>{
    @Override
    public int compare(Integer r1, Integer r2) {
        return r1.compareTo(r2);
    }
}
