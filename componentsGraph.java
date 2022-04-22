import java.util.*;

public class componentsGraph {
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

    public static void findComponents(ArrayList<Edge>[] graph, int src, ArrayList<Integer> list, boolean[] visited) {
        if (visited[src] == true) {
            return;
        }
        visited[src] = true;
        list.add(src);
        for (Edge ele : graph[src]) {
            if (visited[ele.nbr] == false) {
                findComponents(graph, ele.nbr, list, visited);
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
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                ArrayList<Integer> list = new ArrayList<>();
                findComponents(graph, i, list, visited);
                ans.add(list);
            }
        }
        for (ArrayList<Integer> ele : ans) {
            System.out.println(ele);
        }
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
/*abstract


7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

*/
// !GET CONNECTED COMPONENTS OF GRAPH