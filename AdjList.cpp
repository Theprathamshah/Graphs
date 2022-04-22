#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int>graph[n];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    return 0;
}
