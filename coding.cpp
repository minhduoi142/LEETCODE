#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
int v[1000];
int segTree[1000];

void buildSegTree(int index, int l, int r)
{
    if (l == r)
    {
        segTree[index] = v[l];
    }
    else
    {

        int m = (l + r) / 2;

        buildSegTree(index * 2, l, m);
        buildSegTree(index * 2 + 1, m + 1, r);

        segTree[index] = segTree[index * 2] + segTree[index * 2 + 1];
    }
}

void solve()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    buildSegTree(1, 0, n - 1);

    for (int i = 1; i <= n * 4; i++)
    {
        cout << segTree[i] << " ";
    }
}

signed main()
{
    // CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
}