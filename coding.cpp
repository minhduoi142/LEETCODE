#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

vector<vector<string>> ans;

void dfs(string word, string beginWord, unordered_map<string, int> &mpp, vector<string> &seq)
{

    if (beginWord == word)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int len = word.size();

    for (int i = 0; i < len; i++)
    {

        string temp = word;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            temp[i] = ch;
            if (mpp.count(temp) && mpp[word] - 1 == mpp[temp])
            {
                seq.push_back(temp);
                dfs(temp, beginWord, mpp, seq);
                seq.pop_back();
            }
        }
    }
}

void solve()
{

    string beginWord;
    string endWord;
    cin >> beginWord >> endWord;
    vector<string> wordList;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        wordList.push_back(x);
    }

    unordered_set<string> words;
    unordered_map<string, int> mpp;
    queue<string> q;

    for (string x : wordList)
    {
        words.insert(x);
    }

    q.push(beginWord);
    mpp[beginWord] = 1;
    words.erase(beginWord);

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        int len = curr.size();
        int step = mpp[curr];
        for (int i = 0; i < len; i++)
        {
            char ori = curr[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                curr[i] = ch;
                if (words.count(curr) && ch != ori)
                {
                    mpp[curr] = step + 1;
                    q.push(curr);
                    words.erase(curr);
                }
            }
            curr[i] = ori;
        }
        /* code */
    }

    vector<string> seq = {endWord};
    dfs(endWord, beginWord, mpp, seq);

    for (auto x : ans)
    {
        for (string y : x)
        {
            cout << y << " ";
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