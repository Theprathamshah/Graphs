#include <bits/stdc++.h>
using namespace std;

void addDirectedEdge(vector<pair<int, int>> *adj, int u, int v, int wt)
{
    if (wt)
    {
        adj[u].push_back({v, wt});
        return;
    }
    adj[u].push_back({v, 0});
}

void addUndirectedEdge(vector<pair<int,int>>*adj,int u,int v,int wt)
{
    if(wt)
    {
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
        return;
    }
    adj[u].push_back({v,0});
    adj[v].push_back({u,0});
}



void dfs(vector<pair<int, int>> adj[], int src, vector<bool> &vis)
{
    vis[src] = true;
    cout<<src<<" "<<" ";
    for (auto ele : adj[src])
    {
        if (vis[ele.first] == false)
        {
            dfs(adj, ele.first, vis);
            cout<<ele.first<<" "<<ele.second<<endl;
        }
    }
}

bool isCyclePresent(vector<pair<int,int>>adj[],int n,int src)
{
    queue<int>q;
    q.push(src);
    vector<bool>vis(n,false);
    while(!q.empty())
    {
        auto rem = q.front();
        q.pop();
        if(vis[rem])
        {
            return true;
        }
        vis[rem] = true;
        for(auto ele:adj[rem])
        {
            if(vis[ele.first]==false)
            {
                q.push(ele.first);
            }
        }
    }
    return false;
}

int main()
{
    int n, m, u, v,wt;
    cin >> n;
    vector<pair<int, int>> adj[n];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v>>wt;
        addUndirectedEdge(adj, u, v, wt);
    }

    int src;
    cin >> src;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {

            dfs(adj, i, vis);
        }
    }
    cout << endl;

    return 0;
}

//  7
//  8
//  0 1 10
//  0 3 40
//  1 2 10
//  2 3 10
//  3 4 2
//  4 5 3
//  4 6 8
//  5 6 3
//  0
