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

void bfs(vector<Edge> graph[], int src, vector<bool> &vis)
{
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
    vector<bool> vis(n,0);
    queue<pair<int, string>> q;
    int src;
    cin >> src;
    q.push({src, to_string(src) + " "});

    while (!q.empty())
    {
        /* code */
        int temp = q.front().first;
        string pre = q.front().second;
        q.pop();
        cout << temp << " @ " << pre << endl;
        if(vis[temp]==true)
        {
            continue;
        }
        vis[temp] = true;
        for (auto ele : graph[temp])
        {
            if (vis[ele.nbr] == false)
            {
                q.push({ele.nbr, pre + to_string(ele.nbr) + " "});
            }
        }
    }

    return 0;
}
