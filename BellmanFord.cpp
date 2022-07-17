#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int src, nbr, wt;
    node(int s, int n, int w)
    {
        src = s;
        nbr = n;
        wt = w;
    }
};

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<node> adj;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back(node(u, v, w));
        // adj.push_back(node(v, u, w));
    }

    vector<int> dis(n, 1e7);
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ele : adj)
        {
            if (dis[ele.src] + ele.wt < dis[ele.nbr])
            {
                dis[ele.nbr] = dis[ele.src] + ele.wt;
            }
        }
        /* code */
    }

    bool flag = 0;
    for (auto ele : adj)
    {
        if (dis[ele.src] + ele.wt < dis[ele.nbr])
        {
            cout << -1 << endl;
            flag = 1;
            break;
        }
    }

    for (auto ele : dis)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
/*


    edges.push_back(node(0,1,5));
    edges.push_back(node(1,2,-2));
    edges.push_back(node(1,5,-3));
    edges.push_back(node(2,4,3));
    edges.push_back(node(3,2,6));
    edges.push_back(node(3,4,-2));
    edges.push_back(node(5,3,1));

6
7
0 1 5
1 2 -2
1 5 -3
2 4 3
3 2 6
3 4 -2
5 3 1
0
-1


*/