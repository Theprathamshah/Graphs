#include<bits/stdc++.h>
using namespace std;

void primsAlgorithm(vector<pair<int,int>>adj[],int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({})
}
 
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int u,v,wt;
    vector<pair<int, int> >adj[n];
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({u,wt});
        adj[v].push_back({v,wt});
    }


    
    return 0;
}
