#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int vis[20][20] = {0};
int res = 0;
bool start = true;

void backtrack(int i, int j, int m, int n, int m_target, int n_target, vector<vector<int>> &grid)
{

    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1)
    {
        return;
    }
    if (i == n_target && j == m_target)
    {
        for (int l = 0; l < n; l++)
        {
            for (int k = 0; k < m; k++)
            {
                if (grid[l][k] == 0)
                {
                    return;
                }
            }
        }

        res++;
        return;
    }
    start = false;

    int temp = grid[i][j];
    grid[i][j] = -1;

    backtrack(i + 1, j, m, n, m_target, n_target, grid);
    backtrack(i, j + 1, m, n, m_target, n_target, grid);
    backtrack(i - 1, j, m, n, m_target, n_target, grid);
    backtrack(i, j - 1, m, n, m_target, n_target, grid);

    grid[i][j] = temp;
}

void solve()
{

    int m, n;

    cin >> m >> n;
    vector<vector<int>> grid(n);
    int m_target;
    int n_target;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int temp;
            cin >> temp;

            grid[i].push_back(temp);
            if (grid[i][j] == 1)
            {
                x = i, y = j;
            };
            if (grid[i][j] == 2)
            {
                n_target = i;
                m_target = j;
            }
        }
    }

    backtrack(x, y, m, n, m_target, n_target, grid);
    cout << res;
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