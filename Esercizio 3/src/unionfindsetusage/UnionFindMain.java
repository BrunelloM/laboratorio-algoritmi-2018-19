package unionfindsetusage;

import unionfindset.*;

public class UnionFindMain {
    public static void main(String[] args) {
        try {
            UnionFind<Integer> unionFind = new UnionFind<Integer>();
            for(int i = 0; i < 10; i++)
                unionFind.makeSet(i);

            unionFind.print();


            unionFind.union(1, 5);
            unionFind.union(0, 5);

            unionFind.print();
        } catch(SetException e) {
            e.printStackTrace();
        }

    }
}
