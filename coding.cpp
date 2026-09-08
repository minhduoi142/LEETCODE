#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int m, n;
vector<vector<int>> vis(n, vector<int>(m, 0));

void dfs(vector<vector<char>> &board, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || board[x][y] != 'O')
        return;

    board[x][y] = '#';

    dfs(board, x + 1, y);
    dfs(board, x - 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
}

void solve()
{

    cin >> m >> n;
    vector<vector<char>> board(n);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            board[i].push_back(x);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
            dfs(board, i, m - 1);
        if (board[i][0] == 'O')
            dfs(board, i, 0);
    }

    for (int j = 0; j < m; j++)
    {
        if (board[0][j] == 'O')
            dfs(board, 0, j);
        if (board[n - 1][j] == 'O')
            dfs(board, n - 1, j);
    }

    for (auto &x : board)
    {
        for (char &y : x)
        {
            if (y == '#')
            {
                y = 'O';
            }
            else if (y == 'O')
            {
                y = 'X';
            }
        }
    }

    for (auto x : board)
    {
        for (char y : x)
        {
            cout << y;
        }
        cout << endl;
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