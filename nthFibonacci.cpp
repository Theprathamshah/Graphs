#include <bits/stdc++.h>
using namespace std;

int getNthFibonacci(int n)
{
    int first = 0;
    int second = 1;
    for (int i = 0; i < n; i++)
    {
        int temp = first + second;
        second = first;
        first = temp;
    }
    return first;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if(n<0)
        {
            break;
        }
        cout << getNthFibonacci(n) << endl;
    }
    return 0;
}
