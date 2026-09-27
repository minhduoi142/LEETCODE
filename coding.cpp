#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int vis[2000];

void dfs(int curr, vector<vector<int>> &g)
{
    cout << curr << " ";

    if (vis[curr] == 0)
    {
        vis[curr] = 1;
        for (int x : g[curr])
        {
            if (!vis[x])
                dfs(x, g);
        }
    }
}

void solve()
{

    int numCourse;
    int n, m;
    cin >> numCourse;
    cin >> m >> n;

    vector<vector<int>> prerequisites;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        prerequisites.push_back({a, b});
    }

    for (int i = 0; i < n; i++)
    {
        g[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (vector<int> x : g)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    dfs(0, g);
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