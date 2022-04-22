#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int nbr;
    int wt;
    Edge(int source, int neighbour, int weight)
    {
        src = source;
        nbr = neighbour;
        int wt = weight;
    }
};


void printAllPaths(vector<Edge>graph[],int src,vector<bool>&vis,string ans,int destination)
{
    if(src==destination)
    {
        cout<<ans<<endl;
    }
    vis[src]=true;
    for(auto ele:graph[src])
    {
        if(vis[ele.nbr]==false)
        {
            printAllPaths(graph,ele.nbr,vis,ans+to_string(ele.nbr) + " ",destination);
        }

    }
    vis[src] = false;
}

int main()
{
    int n;
    cin >> n;
    vector<Edge> graph[n];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int src, nbr, wt;
        cin >> src >> nbr >> wt;
        graph[src].push_back(Edge(src, nbr, wt));
        graph[nbr].push_back(Edge(nbr, src, wt));
    }
    int src;
    cin>>src;
    int destination;
    cin>>destination;
    vector<bool>vis(n,false);
    printAllPaths(graph,src,vis,to_string(src) + " ",destination);
    return 0;
}