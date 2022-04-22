#include <bits/stdc++.h>
using namespace std;
void addDirectedEdge(int u, int v, int wt, vector<pair<int, int>> *graph)
{
    graph[u].push_back({v, wt});
}
void addUndirectedEdge(int u, int v, int wt, vector<pair<int, int>> *graph)
{
    graph[u].push_back({v, wt});
    graph[v].push_back({u, wt});
}
struct Comparable
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void deapthFirstSearch(vector<pair<int, int>> graph[], int src, vector<bool> &seen)
{
    seen[src] = true;
    cout << src << " ";
    for (auto ele : graph[src])
    {
        if (seen[ele.first] == false)
        {
            deapthFirstSearch(graph, ele.first, seen);
        }
    }
}
void breadthFirstSearchForGraph(vector<pair<int, int>> graph[], int src, int n)
{
    vector<bool> seen(n, false);
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int rem = q.front();
        q.pop();
        if (seen[rem] == true)
        {
            continue;
        }
        seen[rem] = true;
        cout << rem << " ";
        for (auto ele : graph[rem])
        {
            if (seen[ele.first] == false)
            {
                q.push(ele.first);
            }
        }
    }
    cout << "\n";
}

class node
{
public:
    int src, nbr, wt;
    node(int src1, int nbr1, int wt1)
    {
        src = src1;
        nbr = nbr1;
        wt = wt1;
    }
};

void bellmanFordPrathz(vector<node> graph, int src, int n)
{
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ele : graph)
        {
            if (dis[ele.src] + ele.wt < dis[ele.nbr])
            {
                dis[ele.nbr] = dis[ele.src] + ele.wt;
            }
        }
        /* code */
    }

    for (auto ele : graph)
    {
        if (dis[ele.src] + ele.wt < dis[ele.nbr])
        {
            cout << "Negative cycle\n";
            return;
        }
    }

    for (auto ele : dis)
    {
        cout << ele << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v, wt;
    cin >> n;
    vector<node> graph;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        graph.push_back(node(u, v, wt));
    }
    bellmanFordPrathz(graph, 0, n);
    return 0;
}
/*
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
*/
/*
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

/*

!BELLMAN FORDS INPUT

6 9
0 1 6
0 2 4
3 2 -2
0 3 5
2 1 -2
1 4 -1
2 4 3
3 5 -1 +
4 5 3
Negative Cycle

*/