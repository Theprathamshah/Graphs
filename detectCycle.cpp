#include <bits/stdc++.h>
using namespace std;

bool isCyclePresent(vector<int>graph[],int src,vector<bool>&visited)
{
    if(visited[src]==true)
    {
        return true;
    }
    visited[src] = true;
    for(auto ele:graph[src])
    {
        if(visited[ele]==false)
        {
            if(isCyclePresent(graph,ele,visited))
            {
                return true;
            }
        }
        else if(visited[ele]==true)
        {
            return true;
        }
    }
    return false;

}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool>vis(n,false);
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(vis[i]==false)
        {
            if(isCyclePresent(graph,i,vis))
            {
                cout<<"Cycle present in the graph"<<endl;
                return 0;
                break;

            }
        }
    }
    cout<<"Cycle is not present in the graph"<<endl;

    return 0;
}

