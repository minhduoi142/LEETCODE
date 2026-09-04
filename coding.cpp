#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
bool isvalid(string s)
{
    stack<char> st;

    int len = s.size();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return true;
}
void solve()
{
    string s;
    cin >> s;
    vector<string> res;
    set<string> ans;
    queue<string> q;

    bool found = false;
    q.push(s);

    while (!q.empty())
    {

        string curr = q.front();
        q.pop();

        if (isvalid(curr))
        {
            ans.insert(curr);
            found = true;
        }

        if (found)
            continue;

        int len = curr.size();

        for (int i = 0; i < len; i++)
        {
            if (curr[i] != '(' && curr[i] != ')')
                continue;
            string temp = curr.substr(0, i) + curr.substr(i + 1);
            q.push(temp);
        }
    }
    for (auto x : ans)
    {
        res.push_back(x);
    }

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
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