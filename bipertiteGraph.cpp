#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int src, nbr, wt;
    node(int u, int v, int w)
    {
        src = u;
        nbr = v;
        wt = w;
    }
};

bool isBipertite(vector<int> graph[], int src, int n)
{
    queue<int> q;
    q.push(src);
    int color = 1;
    vector<int> col(n, -1);
    while (!q.empty())
    {
        auto rem = q.front();
        q.pop();
        if (col[rem] != -1)
        {
            continue;
        }
        col[rem] = 1 - color;
        for (auto ele : graph[rem])
        {
            if (col[ele] == col[rem])
                return false;
            else if (col[ele] == -1)
            {
                continue;
            }
            else
            {
                col[ele] = 1 - col[rem];
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> graph[n];

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isBipertite(graph, 0, n))
    {
        cout << "Graph is bipartite" << endl;
    }
    else
    {
        cout << "Graph is not bipartite" << endl;
    }

    return 0;
}

/*

9
9
8 7
0 1
1 2
2 3
3 4
4 6
6 7
1 7
4 5

*/