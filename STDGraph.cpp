#include <bits/stdc++.h>
using namespace std;
void addDirectedEdge(int u, int v, int wt, vector<pair<int, int>> *graph)
{
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

void kahnsAlgorithm(vector<pair<int,int>>graph[],int src,int n)
{
    queue<int> q;
    vector<int> indegree(n);
    for (int i = 0;i<n;i++)
    {
        for(auto ele:graph[i])
        {
            indegree[ele.first]++;
        }
    }

    for (int i = 0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int rem = q.front();
        q.pop();
        cout << rem << " ";
        for(auto ele:graph[rem])
        {
            indegree[ele.first]--;
            if(indegree[ele.first]==0)
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
    kahnsAlgorithm(graph, 0, n);
    cout << "\n";
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

/*


!directed graph 

6
6
5 0 10
5 2 10
2 3 10
3 1 10
4 0 10
4 1 10
4 5 0 2 3 1 

*/