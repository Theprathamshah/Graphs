#include<bits/stdc++.h>
using namespace std;
 
struct node{
    int src;
    int nbr;
    int wt;
    node(int s,int n,int w)
    {
        src = s;
        nbr = n;
        wt = w;
    }
};

struct Comparable{
    // public:
    bool operator()(node a,node b)
    {
        return a.wt>b.wt;
    }
};

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<node>adj[n];
    priority_queue<node,vector<node>,Comparable>pq;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj->push_back(node(a,b,c));
    }

    int src;
    cin>>src;
    pq.push(node(src,src,0));
    vector<bool>visited(n,false);
    while(pq.empty()==false)
    {
        node rem = pq.top();
        pq.pop();
        if(visited[rem.src]==true)
        {
            continue;
        }
        visited[rem.src] = true;
        cout<<"At "<<rem.src<<" @ "<<rem.wt<<endl;
        for(auto ele:adj[rem.src])
        {
            if(visited[ele.nbr]==false)
            {
                pq.push(node(ele.nbr,ele.src,ele.wt+rem.wt));
            }
        }
    }

    
    return 0;
}
