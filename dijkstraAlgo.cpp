#include <bits/stdc++.h>
using namespace std;

void addDirectedEdge(int u, int v, int wt, vector<pair<int, int>> *graph)
{
    // graph[u].push_back({v, wt});
    graph[u].push_back({v, wt});
}

void addUndirectedEdge(int u, int v, int wt, vector<pair<int, int>> *graph)
{
    graph[u].push_back({v, wt});
    graph[v].push_back({u, wt});
}

struct Comparable
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void dijkstraAlgorithm(vector<pair<int, int>> graph[], int src, int n)
{
    vector<bool> seen(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparable> q;
    q.push({src, 0});
    while (!q.empty())
    {
        auto rem = q.top();
        q.pop();

        if (seen[rem.first])
        {
            continue;
        }
        seen[rem.first] = true;
        cout << "At " << rem.first << " @ " << rem.second << "\n";
        for (auto ele : graph[rem.first])
        {
            if (!seen[ele.first])
            {
                q.push({ele.first, rem.second + ele.second});
            }
        }
    }
    cout << "\n";
}

void deapthFirstSearch(vector<pair<int, int>> graph[], int src, vector<bool> &seen)
{
    seen[src] = true;
    cout << src << " ";
    for (auto ele : graph[src])
    {
        if (seen[ele.first] == false)
        {
            deapthFirstSearch(graph, ele.first, seen);
        }
    }
}

bool hasACycleUsingDfs(vector<pair<int, int>> graph[], int src, vector<bool> &seen)
{
    if (seen[src] == true)
    {
        return true;
    }

    seen[src] = true;
    for (auto ele : graph[src])
    {
        if (seen[ele.first] == true)
        {
            return true;
        }
        hasACycleUsingDfs(graph, ele.first, seen);
    }
    return false;
}

void breadthFirstSearchForGraph(vector<pair<int, int>> graph[], int src, int n)
{
    vector<bool> seen(n, false);
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int rem = q.front();
        q.pop();
        if (seen[rem] == true)
        {
            continue;
        }
        seen[rem] = true;
        cout << rem << " ";
        for (auto ele : graph[rem])
        {
            if (seen[ele.first] == false)
            {
                q.push(ele.first);
            }
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, u, v, wt;
    cin >> n;
    vector<pair<int, int>> graph[n];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        addDirectedEdge(u, v, wt, graph);
    }
    breadthFirstSearchForGraph(graph, 0, n);
    vector<bool> seen(n, false);
    deapthFirstSearch(graph, 0, seen);
    cout << "\n";
    dijkstraAlgorithm(graph, 0, n);
    fill(seen.begin(), seen.end(), false);
    if (hasACycleUsingDfs(graph, 0, seen) == true)
    {
        cout << "Graph contains cycle\n";
    }
    else
    {
        cout << "Graph doesn't contains cycle\n";
    }
    return 0;
}

/*

7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6

*/

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
