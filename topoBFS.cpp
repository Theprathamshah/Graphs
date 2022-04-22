#include <bits/stdc++.h>
using namespace std;

vector<int> solutionOfTopologicalSort(vector<int> adj[], int N)
{
	queue<int> q;
	vector<int> indegree(N, 0);
	for (int i = 0; i < N; i++)
	{
		for (auto it : adj[i])
		{
			indegree[it]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	vector<int> topo;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for (auto it : adj[node])
		{
			indegree[it]--;
			if (indegree[it] == 0)
			{
				q.push(it);
			}
		}
	}
	return topo;
}

int main()
{
	int u, v;
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> adj[n];
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> ans = solutionOfTopologicalSort(adj, n);
	for (auto ele : ans)
	{
		cout << ele << " ";
	}
	cout << endl;

	return 0;
}
/***************
 *
 *
 *
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