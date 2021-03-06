

import java.util.*;

public class primsAlgo {
    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static class pair implements Comparable<pair> {
        int src;
        int wt;
        int parent;
        pair(int src,int parent,int wt)
        {
            this.src = src;
            this.parent = parent;
            this.wt = wt;
        }
        public int compareTo(pair p)
        {
            return this.wt-p.wt;
        }
    }

    public static void primsAlgorithm(ArrayList<Edge>[]graph,int src)
    {
        int n = graph.length;
        PriorityQueue<pair>pq = new PriorityQueue<>();
        pq.add(new pair(src, -1, 0));
        boolean []visited = new boolean[n];
        while (pq.isEmpty()==false) {
            pair rem = pq.remove();
            if(visited[rem.src]==true)
            {
                continue;
            }
            visited[rem.src] = true;
            if(rem.parent!=-1)
            {
                System.out.println("To "+ rem.src + " via " + rem.parent + " @ " + rem.wt);
            }
            for(Edge ele:graph[rem.src])
            {
                if(visited[ele.nbr]==false)
                {
                    pq.add(new pair(ele.nbr,rem.src,ele.wt));
                }
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Edge>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int src = sc.nextInt();
            int nbr = sc.nextInt();
            int wt = sc.nextInt();
            graph[src].add(new Edge(src, nbr, wt));
            graph[nbr].add(new Edge(nbr, src, wt));
        }
        int src = sc.nextInt();
        System.out.println("Solution of prim's algorithm is given below");
        primsAlgorithm(graph, src);
    }
}
/*
 * basic graph input
 * 7
 * 8
 * 0 1 10
 * 1 2 10
 * 2 3 10
 * 0 3 10
 * 3 4 10
 * 4 5 10
 * 5 6 10
 * 4 6 10
 * 0
 * 6
 */
/*
 * 7
 * 8
 * 0 1 10
 * 0 3 40
 * 1 2 10
 * 2 3 10
 * 3 4 2
 * 4 5 3
 * 4 6 8
 * 5 6 3
 * 0
 */
/*
 * 7
 * 5
 * 0 1 10
 * 2 3 10
 * 4 5 10
 * 5 6 10
 * 4 6 10
 */

 /*abstract


 7
8
0 1 10
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
4 6 8 --*
5 6 3
0

*/