import java.util.*;

public class graphInJava {
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

    public static ArrayList<Integer> bfs(ArrayList<Edge>[] graph, int src) {
        int n = graph.length;
        ArrayList<Integer> list = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];
        q.add(src);
        // list.add(src);
        while (q.size() > 0) {
            int temp = q.remove();
            if (visited[temp] == true) {
                continue;
            }
            visited[temp] = true;
            list.add(temp);
            for (Edge ele : graph[temp]) {
                if (visited[ele.nbr] == false) {
                    q.add(ele.nbr);
                }
            }
        }
        return list;
    }

    public static ArrayList<Integer> dfs(ArrayList<Edge>[] graph, int src) {
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> list = new ArrayList<>();
        int n = graph.length;
        boolean[] visited = new boolean[n];
        st.push(src);
        while (st.size() != 0) {
            int temp = st.pop();
            if (visited[temp] == true) {
                continue;
            }
            visited[temp] = true;
            list.add(temp);
            for (Edge ele : graph[temp]) {
                if (visited[ele.nbr] == false) {
                    st.push(ele.nbr);
                }
            }
        }
        return list;
    }

    public static void printAllPaths(ArrayList<Edge>[]graph,int src,int destination,boolean[]visited,String ans)
    {
        if(src==destination)
        {
            ans+=destination;
            System.out.println(ans);
            return;
        }
        if(visited[src]==true)
        {
            return;
        }
        visited[src] = true;
        ans+=src + " ";
        for(Edge ele:graph[src])
        {
            if(visited[ele.nbr]==false)
            {
                printAllPaths(graph, ele.nbr, destination, visited, ans);
                visited[ele.nbr]=false;
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
        int destination = sc.nextInt();
        System.out.println("Breadth first traversal of this graph is given below");
        ArrayList<Integer> ansBFS = bfs(graph, src);
        System.out.println(ansBFS);
        System.out.println("Depth first traversal of this graph is given below");
        ArrayList<Integer> ansDFS = dfs(graph, src);
        System.out.println(ansDFS);
        System.out.println("All paths to reach " + destination + " from source are : ");
        printAllPaths(graph, src, destination, new boolean[n], "");
    }
}

/**
 
*!Fucking good
*TODO COMPELETE ALL FUNCTIONS AND ALGORITHMS FOR GRAPHS
*? HERE WE GO!!!!!!!!!!!!!!!!!!!
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6
Breadth first traversal of this graph is given below
[0, 1, 3, 2, 4, 5, 6]
Depth first traversal of this graph is given below
[0, 3, 4, 6, 5, 2, 1]
All paths to reach 6 from source are : 
0 1 2 3 4 5 6
0 1 2 3 4 6
0 3 4 5 6
0 3 4 6

 */