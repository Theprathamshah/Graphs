#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void floodFill(vector<vector<int>> &arr, int r, int c)
{

    arr[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int row = r + dx[i];
        int col = c + dy[i];
        if (row >= 0 and col >= 0 and row < arr.size() and col < arr[0].size() and arr[row][col] == 1)
        {
            floodFill(arr, row, col);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    cout << endl;
    for (auto ele : arr)
    {
        for (auto i : ele)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
/*

4 4
1 0 0 1
0 1 1 0
0 0 0 1
1 1 1 1

**/