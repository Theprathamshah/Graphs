#include <bits/stdc++.h>
using namespace std;

vector<int> kahns_algorithm(vector<int> graph[],int n)
{
    // int n = graph->size();
    cout<<"Size "<<n<<endl;
    vector<int> ans;
    queue<int> q;
    vector<int> inDegree(n,0);
    for (int i = 0; i < n; i++)
    {
        for (auto ele : graph[i])
        {
            inDegree[ele]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int rem = q.front();
        q.pop();
        ans.push_back(rem);
        for(auto ele:graph[rem])
        {
            inDegree[ele]--;
            if(inDegree[ele] == 0)
            {
                q.push(ele);
            }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    int m;
    cin >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int>ans = kahns_algorithm(adj,n);
    for(auto ele:ans)
    {
        cout<<ele<<" ";
    }
    return 0;
}
