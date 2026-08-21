#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

vector<int> curr;
vector<vector<int>> res;

void backtrack(vector<int> &nums, int i, vector<vector<int>> &res)
{
    if (i == nums.size())
    {
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        curr.push_back(nums[j]);
        res.push_back(curr);
        backtrack(nums, i + 1, res);
        curr.pop_back();
    }
}

void solve()
{

    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    backtrack(nums, 0, res);
    res.push_back({});

    for (vector<int> x : res)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
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