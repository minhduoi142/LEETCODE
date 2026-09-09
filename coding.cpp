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
    bool isWord;
    TrieNode *child[26];

    TrieNode()
    {
        isWord = false;
        for (TrieNode *&x : child)
        {
            x = nullptr;
        }
    }
};

void dfs(TrieNode *&root, int i, string word, bool &check)
{

    if (check == true)
    {
        return;
    }
    if (i == word.size())
    {
        check = true;
    }

    if (word[i] != '.')
    {
        int temp = word[i] - 'a';
        if (root->child[temp] != nullptr)
        {
            dfs(root->child[temp], i + 1, word);
        }
        else
            check = false;
    }
    else if (word[i] == '.')
    {
        for (int j = 0; j <= 26; j++)
        {
            if (root->child[j] != nullptr)
            {
                dfs(root->child[j], i + 1, word);
            }
        }
    }
}

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word)
    {
        TrieNode *r = root;

        for (char c : word)
        {
            int i = c - 'a';

            if (r->child[i] == nullptr)
                r->child[i] = new TrieNode();
            r = r->child[i];
        }
        r->isWord = true;
    }

    bool search(string word)
    {
        TrieNode *r = root;
        if (word == "")
        {
            return true;
        }
        else
        {
            bool check = false;
            dfs(root, 0, word, check);
            return check;
        }
    }
};

void solve()
{
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