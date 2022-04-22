#include<bits/stdc++.h>
using namespace std;
 
bool ispath(int a,int b,int x,int y,int k)
{
    if(a==x and b == y)
    {
        return true;
    } 
    if(a>x or b>y)
    {
        return false;
    }
    return (ispath(a+k,b,x,y,k) | ispath(a,b+k,x,y,k));
}

int main()
{
    while(true)
    {
        int x,y,k;
        cin>>x>>y>>k;
        if(ispath(0,0,abs(x),abs(y),k))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
     return 0;
}
/*

4
1 2 1
3 -5 2
-9 -6 3
-18 12 5

*/