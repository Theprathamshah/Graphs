#include <bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> adj[], stack<int> &st, vector<bool> &seen, int src)
{
    seen[src] = true;
    for (auto ele : adj[src])
    {
        if (seen[ele] == false)
        {
            topologicalSort(adj, st, seen, ele);
        }
    }

    st.push(src);
}

int main(int argc, char const *argv[])
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
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
    }
    stack<int> st;
    int src;
    cin >> src;
    vector<bool> seen(n, false);
    for (int i = 0; i < n; i++)
    {
        if (seen[i] == false)
            topologicalSort(adj, st, seen, i);
    }

    // topologicalSort(adj, st, seen, src);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
/*


 g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

*/

// 6 6
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1
// 0