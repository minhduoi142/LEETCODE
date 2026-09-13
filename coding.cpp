#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

vector<string> res;

class TrieNode
{
public:
    bool isNum;
    TrieNode *child[26];
    TrieNode()
    {
        for (TrieNode *&x : child)
        {
            isNum = false;
            x = nullptr;
        }
    }

    void insert(TrieNode *r, string word)
    {

        for (char c : word)
        {
            int i = c - '0';

            if (r->child[i] == nullptr)
                r->child[i] = new TrieNode();
            r = r->child[i];
        }
        r->isNum = true;
    }

    void dfs(TrieNode *r, string &curr)
    {
        if (r->isNum)
        {
            res.push_back(curr);
        }

        for (int i = 0; i <= 9; i++)
        {
            if (r->child[i] != nullptr)
            {
                curr.push_back('0' + i);
                dfs(r->child[i], curr);
                curr.pop_back();
            }
        }
    }
};

void solve()
{

    int n;
    cin >> n;

    vector<int> ve(n + 1);

    TrieNode *r = new TrieNode();
    for (int i = 1; i <= n; i++)
    {
        r->insert(r, to_string(i));
    }

    string curr = "";
    r->dfs(r, curr);
    vector<int> ans;

    for (const string &s : res)
    {
        ans.push_back(stoll(s));
    }

    for (int x : ans)
    {
        cout << x << " ";
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