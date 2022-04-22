import java.util.*;

public class bellmanFord {
    static class Edge implements Comparable<Edge>{
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
        public int compareTo(Edge object)
        {
            return this.wt - object.wt;
        }
    }

    public static void printGraph(ArrayList<Edge>[] graph, int src, int m) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        int[] distance = new int[n];
        for (int i = 0; i < distance.length; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[src] = 0;
        PriorityQueue<Edge>q = new PriorityQueue<>();
        q.add(new Edge(src, src, 0));

        while (q.isEmpty() == false) {
            Edge rem = q.remove();
            if (visited[rem.src] == true) {
                continue;
            }
            visited[rem.src] = true;

            // System.out.println(rem.src + " " + rem.nbr + " " + rem.wt);

            for (int i = 0; i < graph[rem.src].size(); i++) {
                int u = graph[rem.src].get(i).src;
                int v = graph[rem.src].get(i).nbr;
                int weight = graph[rem.src].get(i).wt;
                if(distance[u]!=Integer.MAX_VALUE && distance[u]+weight<distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
                if(visited[v]==false)
                {
                    q.add(new Edge(v,src,weight));
                }
            }

        }
        for (int i = 0; i < distance.length; i++) {
            System.out.println("Distance of " + i + " vertex from " + src + " -> " + distance[i]);
        }
    }

    public static void bellmanFordSolution(ArrayList<Edge>[] graph, int src, int m) {
        int n = graph.length;
        int[] distance = new int[n];

        for (int i = 0; i < distance.length; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        distance[src] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int u = graph[i].get(j).src;
                int v = graph[i].get(j).nbr;
                int weight = graph[i].get(j).wt;
                if (distance[u] != Integer.MAX_VALUE && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
        for (Edge ele : graph[src]) {
            int u = ele.src;
            int v = ele.nbr;
            int wt = ele.wt;
            if (distance[u] != Integer.MAX_VALUE && distance[u] + wt < distance[v]) {
                System.out.println("Graph contains negative cycle");
                return;
            }
        }
        for (int i = 0; i < distance.length; i++) {
            System.out.println("Distance of " + i + " vertex from " + src + " -> " + distance[i]);
        }
        // printGraph(graph, src);
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
        // bellmanFordSolution(graph, src, m);
        printGraph(graph, src, m);
        sc.close();
        // printGraph(graph, src);
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

/*
 * abstract
 * 
 * 
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
 * 
 */

/*
 * abstract
 * 
 * 
 * 
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
 * Distance of 0 vertex from 0 -> 0
 * Distance of 1 vertex from 0 -> 10
 * Distance of 2 vertex from 0 -> 20
 * Distance of 3 vertex from 0 -> 30
 * Distance of 4 vertex from 0 -> 32
 * Distance of 5 vertex from 0 -> 35
 * Distance of 6 vertex from 0 -> 38
 * 
 */

// 7
// 8
// 0 1 10
// 0 3 40
// 1 2 10
// 2 3 10
// 3 4 2
// 4 5 3
// 4 6 8
// 5 6 3
// 0