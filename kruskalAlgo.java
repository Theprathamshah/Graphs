import java.util.*;

public class kruskalAlgo {
    static class Edge implements Comparable<Edge> {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }

        public int compareTo(Edge object) {
            return this.wt - object.wt;
        }
    }

    public static void kruskalAlgorithmSolution(ArrayList<Edge>[] graph, int src) {
        int n = graph.length;
        for (int i = 0; i < n; i++) {
            Collections.sort(graph[i]);
        }
        boolean []visited = new boolean[n];
        Queue<Edge> q= new LinkedList<>();
        q.add(new Edge(src, -1, 0));
        while (q.isEmpty()==false) {
            Edge rem =q.remove();
            if(visited[rem.src]==true)
            {
                continue;
            }
            visited[rem.src]=true;
            if(rem.nbr!=-1)
            {
                System.out.println("At " + rem.src + " via " + rem.nbr + " @ " + rem.wt);
            }
            for(Edge ele:graph[rem.src])
            {
                if(visited[ele.nbr]==false)
                {
                    q.add(new Edge(ele.nbr,rem.src,ele.wt));
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
        // int destination = sc.nextInt();
        kruskalAlgorithmSolution(graph, src);

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


*/