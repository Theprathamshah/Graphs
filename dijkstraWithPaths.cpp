#include <bits/stdc++.h>
using namespace std;


class triplet
{
    public:
    int src;
    string psf;
    int wsf;
    triplet(int s,string str,int wt)
    {
        src = s;
        psf = str;
        wsf = wt;
    }
   
};

class Comparable
{
    public:
    bool operator()(triplet const&a,triplet const&b)
    {
        return a.wsf>b.wsf;
    }
};

// void dijkstraAlgoForAdjList(vector<pair<int, int>> graph[], int src)
// {
//     priority_queue<pair<int,int>, vector<pair<int,int>>,Comparable> pq;
//     cout << "Implementation of Dijkstra Algorithm" << endl;
//     pq.push({src,0});
//     int n = graph->size();
//     vector<bool> seen(n, false);
//     // seen[src] = true;
//     while (!pq.empty())
//     {
//         // cout<<pq.size()<<endl;
//         auto rem = pq.top();
//         pq.pop();
//         if (seen[rem.first] == true)
//         {
//             continue;
//         }
//         cout << "At "<<rem.first<<" @ " << rem.second<<endl;
//         seen[rem.first] = true;
//         for (auto ele : graph[rem.first])
//         {
//             if (seen[ele.first] == false)
//             {
//                 pq.push({ele.first,rem.second + ele.second});
//             }
//         }
//     }
//     cout << endl;
// }

void dijkstraAlgorithmWithPaths(vector<pair<int,int>>graph[],int src)
{
    int n = graph->size();
    priority_queue<triplet,vector<triplet>,Comparable>pq;
    pq.push(triplet(src,to_string(src)+" ",0));
    vector<bool>visited(n,false);
    while (pq.empty()==false)
    {
        auto rem = pq.top();
        pq.pop();
        if(visited[rem.src]==true)
        {
            continue;
        }
        cout<<"At "<<rem.src<<" via "<<rem.psf<<" @ "<<rem.wsf<<endl;
        visited[rem.src] = true;
        for(auto ele:graph[rem.src])
        {
            if(visited[ele.first]==false)
            {
                pq.push(triplet(ele.first,rem.psf+to_string(ele.first)+" ",rem.wsf+ele.second));
            }
        }
    }
    
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
    // dijkstraAlgoForAdjList(graph, src);
    cout<<endl;
    dijkstraAlgorithmWithPaths(graph,src);
    return 0;
}
/*


7
8
0 1 10
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
4 6 8
5 6 3
0

*/




//!  OUTPUT OF THIS CODE
/*
7
8
0 1 10
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
4 6 8
5 6 3
0

At 0 via 0  @ 0
At 1 via 0 1  @ 10
At 2 via 0 1 2  @ 20
At 3 via 0 1 2 3  @ 30
At 4 via 0 1 2 3 4  @ 32
At 5 via 0 1 2 3 4 5  @ 35
At 6 via 0 1 2 3 4 5 6  @ 38

*/