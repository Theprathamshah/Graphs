#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> adj[], vector<bool> &vis, int src, stack<int> &st)
{
    vis[src] = true;
    for (auto ele : adj[src])
    {
        if (vis[ele] == false)
        {
            topologicalSort(adj, vis, ele, st);
        }
    }
    st.push(src);
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            topologicalSort(adj, vis, i, st);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}

//? OUTPUT GOES HERE
/**
 * @brief
 *
6
6
5 0
5 2
4 0
2 3
1 3
4 1
5 4 2 1 3 0
 *
 */

//! INPUT OF THE HACKER EARTH

/*

5 6
1 2
1 3
2 3
2 4
3 4
3 5

*/

//! PEPCODING SAME OLD BANGER

/*


7
8
0 1
0 3
1 2
2 3
4 3
4 5
4 6
5 6
4 5 6 0 1 2 3 

*/