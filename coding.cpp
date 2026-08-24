#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct item
{
    char c;
    int x;
    int y;
};
vector<vector<char>> board(100);
string word;
bool backtrack(int x, int y, int index, int n, int m)
{
    int len = word.size();

    if (index == len)
    {
        return true;
    }
    if (board[x][y] != word[index])
    {
        return false;
    }

    int temp = board[x][y];
    board[x][y] = '#';

    if (x - 1 >= 0)
    {
        if (backtrack(x - 1, y, index + 1, n, m))
            return true;
    }
    if (x + 1 < n)
    {
        if (backtrack(x + 1, y, index + 1, n, m))
            return true;
    }
    if (y - 1 >= 0)
    {
        if (backtrack(x, y - 1, index + 1, n, m))
            return true;
    }
    if (y + 1 < m)
    {
        if (backtrack(x, y + 1, index + 1, n, m))
            return true;
    }

    board[x][y] = temp;
    return false;
}

bool solve()
{

    int m, n;
    cin >> m >> n;

    cin >> word;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            board[i].push_back(x);
        }
    }
    string s = "";
    s += board[0][0];
    cout << s;
    if (n == 1 && m == 1)
    {
        return word == to_string(board[0][0]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (backtrack(i, j, 0, n, m))
                return true;
        }
    }
    return false;
}

signed main()
{
    CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        if (solve())
        {
            cout << "YES";
        }
        else
            cout << "NO";
    }
}