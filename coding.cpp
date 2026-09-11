#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

class TrieNode
{
public:
    string *wordptr;
    TrieNode *child[26];

    TrieNode()
    {
        wordptr = nullptr;
        for (TrieNode *&x : child)
        {
            x = nullptr;
        }
    }
    void insert(TrieNode *r, string &word)
    {

        for (char c : word)
        {
            int i = c - 'a';

            if (r->child[i] == nullptr)
                r->child[i] = new TrieNode();
            r = r->child[i];
        }
        r->wordptr = &word;
    }
};

int n, m;

vector<string> res;
void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node)
{
    if (i >= n || j >= m || i < 0 || j < 0 || board[i][j] == '#')
        return;

    char c = board[i][j];

    if (!node->child[c - 'a'])
        return;
    node = node->child[c - 'a'];
    if (node->wordptr)
    {
        res.push_back(*node->wordptr);
        node->wordptr = nullptr;
    }
    board[i][j] = '#';

    dfs(board, i + 1, j, node);
    dfs(board, i - 1, j, node);
    dfs(board, i, j + 1, node);
    dfs(board, i, j - 1, node);

    board[i][j] = c;
}

void solve()
{
    cin >> n >> m;
    int k;
    vector<vector<char>> board(n);
    vector<string> words;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;

            board[i].push_back(x);
        }
    }

    cin >> k;
    TrieNode *node = new TrieNode();

    for (int i = 0; i < k; i++)
    {
        string x;
        cin >> x;
        words.push_back(x);
    }
    for (string &s : words)
    {
        node->insert(node, s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(board, i, j, node);
        }
    }

    for (string s : res)
    {
        cout << s << " ";
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