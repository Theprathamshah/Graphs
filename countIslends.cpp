#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void floodFill(vector<vector<int>> &arr, int r, int c)
{
    if ( r < 0 or c < 0 or r >= arr.size() or c >= arr[0].size() or arr[r][c] == 0 )
    {
        return;
    }
    arr[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int row = r + dx[i];
        int col = c + dy[i];
        floodFill(arr, row, col);
    }
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (auto &i : arr)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }

    // cout << dx[0] << " " << dy[1] << " " << dx[2] << " " << dy[3] << endl;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                floodFill(arr, i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
/*

4 4
1 0 0 1
0 1 1 0
0 0 0 1
1 1 1 1

**/