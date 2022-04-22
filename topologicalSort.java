import java.util.*;

public class topologicalSort {
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

    public static void topologicalSortSolution(ArrayList<Edge>[]graph,int src,boolean[]visited,Stack<Integer>st)
    {
        visited[src] = true;
        for(Edge ele:graph[src])
        {
            if(visited[ele.nbr]==false)
            {
                topologicalSortSolution(graph, ele.nbr, visited, st);
            }
        }
        st.push(src);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        ArrayList<Edge>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int src = sc.nextInt();
            int nbr = sc.nextInt();
            // int wt = sc.nextInt();
            graph[src].add(new Edge(src, nbr, 0));
            
        }
        Stack<Integer>st = new Stack<>();
        boolean []visited = new boolean[n];
        int src = sc.nextInt();
        // ArrayList<ArrayList<Integer>> l= new ArrayList<>();
        topologicalSortSolution(graph, src, visited, st);
        while (st.empty()==false) {
            System.out.print(st.pop()+" ");
        }
        System.out.println();
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
7
0 1 10
1 2 10 
2 3 10
0 3 10
4 5 10
5 6 10
4 6 10


*/


