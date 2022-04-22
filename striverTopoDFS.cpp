#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}


vector<int> topoSort(int N, vector<int> adj[])
{
    stack<int> st;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (vis[i] == 0)
        {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// { Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{

    int N, E;
    cin >> N >> E;
    int u, v;

    vector<int> adj[N];

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topoSort(N, adj);

    // cout << check(N, res, adj) << endl;
    for(auto ele:res)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
} // } Driver Code Ends

/******
 *
 *

//!  output by striver of bfs topological sort

7
8
0 1
0 3
1 2
2 3
4 3
4 5
4 6
5 6
0 4 1 5 2 6 3

*/
