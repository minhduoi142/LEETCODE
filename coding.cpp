#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
int k, n;
vector<vector<int>> res;

int sum(vector<int> curr)
{
    int res = 0;
    for (int x : curr)
    {
        res += x;
    }

    return res;
}

void backtrack(int i, int num, vector<int> &curr, int k, int n)
{

    if (i == k && sum(curr) == n)
    {
        res.push_back(curr);
        return;
    }

    if (i > k || num > 9)
    {
        return;
    }

    for (int j = num; j <= 9; j++)
    {
        curr.push_back(j);
        backtrack(i + 1, j + 1, curr, k, n);
        curr.pop_back();
    }
}

void solve()
{

    cin >> k >> n;

    vector<int> curr;
    backtrack(0, 1, curr, k, n);

    for (vector<int> x : res)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

signed main()
{
    CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}