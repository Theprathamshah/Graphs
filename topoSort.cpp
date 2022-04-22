#include<bits/stdc++.h>
using namespace std;

void topologicalSortDFS(stack<int>&st,vector<int>adj[],int src,vector<bool>&visited)
{
    visited[src] = true;
    for(auto ele:adj[src])
    {
        if(visited[ele]==false){
            topologicalSortDFS(st,adj,ele,visited);
        }
    }
    st.push(src);
}

 
int main()
{
    int u, v;
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    stack<int>stack;
    vector<bool>visited(n,false);
    for(int i = 0; i < n; i++)
    {
        if(visited[i]==false)
        {
            topologicalSortDFS(stack, adj,i,visited);
        }
    }
    while(!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;
    return 0;
}
/****************************************************************
 * 
 * 
 * 

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
4 5 6 0 1 2 3 

*/