#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int src;
    cin>>src;
    vector<Node*>vec(m);
    for(auto ele:vec)
    {
        cin>>ele.
    }
    Node *graph(src,vec);
    
    

    return 0;
}
