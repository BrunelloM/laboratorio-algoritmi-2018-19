public class UnionFindMain {
    public static void main(String[] args) {
        try {
        UnionFind<Integer> unionFind = new UnionFind<Integer>(new IntegerComparator());
            unionFind.makeSet(1);
            unionFind.makeSet(2);
            unionFind.makeSet(5);
            unionFind.print();
            unionFind.union(1, 5);
            unionFind.print();
        } catch(SetException e) {
            e.printStackTrace();
        //    System.out.println(e.getMessage());
        }

    }
}
