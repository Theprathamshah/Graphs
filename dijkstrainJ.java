import java.util.*;

public class dijkstrainJ {
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
        String psf;
        pair(int src,String psf,int wt)
        {
            this.src = src;
            this.psf = psf;
            this.wt = wt;
        }
        public int compareTo(pair p)
        {
            return this.wt-p.wt;
        }
    }

    public static void dijkstraAlgo(ArrayList<Edge>[]graph,int src)
    {
        PriorityQueue<pair>pq= new PriorityQueue<>();
        int n = graph.length;
        boolean []visited = new boolean[n];
        pq.add(new pair(src,src + " ",0));
        while(pq.isEmpty()==false)
        {
            pair rem = pq.remove();
            if(visited[rem.src]==true)
            {
                continue;
            }
            visited[rem.src] = true;
            System.out.println("At " + rem.src + " via " + rem.psf + " @ " + rem.wt);
            for(Edge ele:graph[rem.src])
            {
                if(visited[ele.nbr]==false)
                {
                    pq.add(new pair(ele.nbr,rem.psf + ele.nbr + " ",rem.wt + ele.wt));
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
        System.out.println("Solution for dijkstra algorithm is given below");
        dijkstraAlgo(graph, src);
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
4 6 8
5 6 3
0
Solution of prim's algorithm is given below
To 1 via 0 @ 10
To 2 via 1 @ 10
To 3 via 2 @ 10
To 4 via 3 @ 2
To 5 via 4 @ 3
To 6 via 5 @ 3

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
4 6 8
5 6 3
0
Solution for dijkstra algorithm is given below
At 0 via 0  @ 0
At 1 via 0 1  @ 10
At 2 via 0 1 2  @ 20
At 3 via 0 1 2 3  @ 30
At 4 via 0 1 2 3 4  @ 32
At 5 via 0 1 2 3 4 5  @ 35
At 6 via 0 1 2 3 4 5 6  @ 38

*/