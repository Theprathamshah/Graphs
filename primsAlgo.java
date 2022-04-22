import java.rmi.ConnectIOException;
import java.util.*;
public class primsAlgo {

    static class Edge
    {
        int src;
        int nbr;
        int wt;
        Edge(int src,int nbr,int wt)
        {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    static class pair implements Comparable<pair>{
        int v;
        int parent;
        int wsf;
        pair(int v,int parent,int wsf)
        {
            this.v = v;
            this.parent = parent;
            this.wsf = wsf;
        }
        public int compareTo(pair o)
        {
            return this.wsf - o.wsf;
        }
    }


    public static void primsAlgorithmFunction(ArrayList<Edge>[]graph,int src)
    {
        int n =graph.length;
        boolean []visited = new boolean[n];
        PriorityQueue<pair>pq = new PriorityQueue<>();
        pq.add(new pair(src, -1, 0));
        while (pq.isEmpty()==false) {
            pair rem = pq.remove();
            if(visited[rem.v]==true)
            {
                continue;
            }
            visited[rem.v] = true;
            if(rem.parent!=-1)
            {
                System.err.println(rem.v + " via " + rem.parent + " @ " + rem.wsf);
            }
            for(Edge ele:graph[rem.v])
            {
                if(visited[ele.nbr]==false)
                {
                    pq.add(new pair(ele.nbr, rem.v, ele.wt));
                }
            }
        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Edge>[]graph = new ArrayList[n];
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
        primsAlgorithmFunction(graph, src);
    }
}
/*abstract



Input

7
8
0 1 10 
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
4 6 8
5 6 3
0

*/

// TODO COMPELETE KRUSKAL ALGORIGHAM ASAP


/*

!OUTPUT OF THE PRIM'S ALGORITHM
7
8
0 1 10 
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
4 6 8
5 6 3
0
1 via 0 @ 10
2 via 1 @ 10
3 via 2 @ 10
4 via 3 @ 2
5 via 4 @ 3
6 via 5 @ 3

*/