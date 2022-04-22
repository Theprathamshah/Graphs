#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> graph[], vector<int> &temp, int src, vector<bool> &seen)
{
    if (seen[src] == true)
    {
        return;
    }
    seen[src] = true;
    temp.push_back(src);
    for (auto ele : graph[src])
    {
        if (seen[ele] == false)
        {
            dfs(graph, temp, ele, seen);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> seen(n, false);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        if (seen[i] == false)
        {
            dfs(graph, temp, i, seen);
            ans.push_back(temp);
        }
    }
    cout << endl;
    for (auto ele : ans)
    {
        for (auto i : ele)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 * @brief
 *
7
5
0 1
2 3
4 5
5 6
4 6
0
 *
 */