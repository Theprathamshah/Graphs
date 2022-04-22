import java.beans.Visibility;
import java.util.*;

public class isNegCycle {
    static class Edge implements Comparable<Edge>{
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

    public static boolean isNegativeCyclePresent(ArrayList<Edge>[] graph, int src) {
        int n = graph.length;
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(src, src, 0));
        boolean[] seen = new boolean[n];
        while (pq.isEmpty() == false) {
            Edge rem = pq.remove();
            if (seen[rem.src] == true) {
                continue;
            }
            seen[rem.src] = true;
            for (Edge ele : graph[rem.src]) {
                int u = ele.src;
                int v = ele.nbr;
                int weight = ele.wt;
                if (distance[u] != Integer.MAX_VALUE && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
                if (seen[v] == false) {
                    pq.add(new Edge(ele.nbr, src, weight));
                }
            }

        }
        for()
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
        int destination = sc.nextInt();
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