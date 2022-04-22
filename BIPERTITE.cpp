#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int src;
    int nbr;
    int wt;
    Edge(int source, int neighbour, int weight)
    {
        src = source;
        nbr = neighbour;
        int wt = weight;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Edge> graph[n];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    return 0;
}

// computations.