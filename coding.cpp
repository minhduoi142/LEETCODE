#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return (a[0] <= b[0]);
}

void solve()
{

    vector<vector<int>> intervals;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        intervals.push_back(temp);
    }

    sort(intervals.begin(), intervals.end(), cmp);

    int len = intervals.size();
    stack<vector<int>> ans;

    ans.push(intervals[0]);

    for (int i = 1; i < len; i++)
    {
        if (intervals[i][0] <= ans.top()[1] && intervals[i][1] >= ans.top()[1])
        {
            ans.top()[1] = intervals[i][1];
        }
        else if (intervals[i][0] <= ans.top()[0] && intervals[i][1] <= ans.top()[1])
        {
            ans.top()[0] = intervals[i][0];
        }
        else if (intervals[i][0] <= ans.top()[1] && intervals[i][1] >= ans.top()[1])
        {
            ans.top()[0] = intervals[i][0];
            ans.top()[1] = intervals[i][1];
        }
        else if (intervals[i][0] >= ans.top()[0] && intervals[i][1] <= ans.top()[1])
        {
        }
        else
            ans.push(intervals[i]);
    }

    vector<vector<int>> res;

    while (!ans.empty())
    {
        cout << ans.top()[0] << " " << ans.top()[1] << endl;
        ans.pop();
        /* code */
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