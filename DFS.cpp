#include<bits/stdc++.h>
using namespace std;
 
void deapthFirstSearch(vector<int>graph[],int src)
{
    int n = graph->size();
    vector<bool>seen(n,false);
    stack<int>st;
    st.push(src);
    cout<<"Deapth first traversal for given graph is given below"<<endl;
    while (!st.empty())
    {
        int rem =st.top();

        st.pop();
        if(seen[rem]==true)
        {
            continue;
        }
        cout<<rem<<" ";
        seen[rem] = true;
        for(auto ele:graph[rem])
        {
            if(seen[ele]==false)
            {
                st.push(ele);
            }
        }

    }
    cout<<endl;
}

void breadthFirstSearch(vector<int>graph[],int src)
{
    queue<int>q;
    q.push(src);
    int n = graph->size();
    cout<<"Breadth first search for given graph is given below"<<endl;
    vector<bool>seen(n,false);
    while(!q.empty())
    {
        auto rem = q.front();
        q.pop();
        if(seen[rem]==true)
        {
            continue;
        }
        cout<<rem<<" ";
        seen[rem]=true;
        for(auto ele:graph[rem])
        {
            if(seen[ele]==false)
            {
                q.push(ele);
            }
        }
    }
    cout<<endl;
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
    int src;
    cin>>src;
    deapthFirstSearch(graph,src);
    breadthFirstSearch(graph,src);
    cout<<endl;
    return 0;
}


