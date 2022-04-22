#include <bits/stdc++.h>
using namespace std;

void breadthFirstSearch(vector<int>graph[],int src)
{
    queue<int>q;
    q.push(src);
    int n = graph->size();
    cout<<"Breadth first search for given graph is given below"<<endl;
    vector<bool>seen(n,false);
    while(!q.empty())
    {
        auto rem = q.front();
        q.pop();
        if(seen[rem]==true)
        {
            continue;
        }
        cout<<rem<<" ";
        seen[rem]=true;
        for(auto ele:graph[rem])
        {
            if(seen[ele]==false)
            {
                q.push(ele);
            }
        }
    }
    cout<<endl;
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
    int src;
    cin>>src;
    breadthFirstSearch(graph,src);
    return 0;
}

// 7
// 8
// 0 1 
// 1 2 
// 2 3 
// 0 3 
// 3 4 
// 4 5 
// 5 6 
// 4 6 
// 0