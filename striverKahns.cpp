#include <bits/stdc++.h>
using namespace std;

vector<int> topo(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
       
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

int main()
{

    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = topo(V, adj);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}

/*


5
4
0 1 
1 2 
3 2 
3 4 
0 3 1 4 2

*/