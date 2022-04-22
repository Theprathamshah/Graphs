#include <bits/stdc++.h>
using namespace std;


class Comparable
{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>b)
    {
        return a.second>b.second;
    }
};

void dijkstraAlgoForAdjList(vector<pair<int, int>> graph[], int src)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>,Comparable> pq;
    cout << "Implementation of Dijkstra Algorithm" << endl;
    pq.push({src,0});
    int n = graph->size();
    vector<bool> seen(n, false);
    // seen[src] = true;
    while (!pq.empty())
    {
        // cout<<pq.size()<<endl;
        auto rem = pq.top();
        pq.pop();
        if (seen[rem.first] == true)
        {
            continue;
        }
        cout << "At "<<rem.first<<" @ " << rem.second<<endl;
        seen[rem.first] = true;
        for (auto ele : graph[rem.first])
        {
            if (seen[ele.first] == false)
            {
                pq.push({ele.first,rem.second + ele.second});
            }
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    int src;
    cin >> src;
    dijkstraAlgoForAdjList(graph, src);
    return 0;
}
