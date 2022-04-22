import java.util.*;
public class dijkstraAlgo {

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
        String psf;
        int wsf;
        pair(int v,String psf,int wsf)
        {
            this.v = v;
            this.psf = psf;
            this.wsf = wsf;
        }
        public int compareTo(pair o)
        {
            return this.wsf - o.wsf;
        }
    }

    public static void dijstraAlgorithmFunction(ArrayList<Edge>[]graph,int src)
    {
        int n = graph.length;
        boolean []visited = new boolean[n];
        PriorityQueue<pair>pq = new PriorityQueue<>();
        pq.add(new pair(src, src + " ", 0));
        while(pq.isEmpty()==false)
        {
            pair temp = pq.remove();
            if(visited[temp.v]==true)
            {
                continue;
            }
            visited[temp.v] = true;
            System.out.println(temp.v + " via "+temp.psf +  " @ " + temp.wsf );
            for(Edge ele:graph[temp.v])
            {
                if(visited[ele.nbr]==false)
                {
                    pq.add(new pair(ele.nbr, temp.psf + ele.nbr +" ", temp.wsf + ele.wt));
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
        dijstraAlgorithmFunction(graph, src);
    }
}


/*abstract




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
0 via 0  @ 0
1 via 0 1  @ 10
3 via 0 3  @ 10
2 via 0 1 2  @ 20
4 via 0 3 4  @ 20
6 via 0 3 4 6  @ 30
5 via 0 3 4 5  @ 30


*/

