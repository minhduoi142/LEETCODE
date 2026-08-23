#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

bool cmp(vector<long long> a, vector<long long> b)
{
    return (a[0] <= b[0]);
}

void solve()
{

    vector<vector<long long>> intervals;
    vector<int> newInterval;
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

    int x, y;
    cin >> x >> y;
    newInterval.push_back(x);
    newInterval.push_back(y);

    vector<vector<int>> res;

    // if(intervals.empty()){
    //     res.push_back(newInterval);
    //     return res;
    // }
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    int len = intervals.size();

    res.push_back(intervals[0]);

    for (int i = 1; i < len; i++)
    {
        if (intervals[i][0] <= res.back()[1])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else
            res.push_back(intervals[i]);
    }

    for (vector<int> x : res)
    {
        cout << x[0] << " " << x[1] << endl;
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