#include <bits/stdc++.h>
using namespace std;

void knightMove(vector<vector<int>> &a, int r, int c,int move)
{
    if (r >= a.size() or c >= a[0].size() or r < 0 or c < 0 or a[r][c] != 0)
    {
        
        return;
    }
    if(move==a.size()*a.size())
    {
        move = a.sizeO()
    }
    knightMove(a,r-2,c+1,move+1);
    knightMove(a,r-1,c+2,move+1);
    knightMove(a,r+1,c+2,move+1);
    knightMove(a,r+2,c+1,move+1);
    knightMove(a,r+2,c-1,move+1);
    knightMove(a,r+1,c-2,move+1);
    knightMove(a,r-1,c-2,move+1);
    knightMove(a,r-2,c-1,move+1);
    a[r][c] = move;

}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));

    return 0;
}
