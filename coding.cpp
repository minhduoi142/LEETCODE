#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
vector<int> nums;
set<vector<int>> res;

void backtrack(int i, vector<int> &curr, vector<int> &nums)
{

    if (i == nums.size() + 1)
    {
        return;
    }

    res.insert(curr);

    for (int j = i; j < nums.size(); j++)
    {
        curr.push_back(nums[j]);
        backtrack(j + 1, curr, nums);
        curr.pop_back();
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());

    vector<int> curr;
    backtrack(0, curr, nums);
    vector<vector<int>> ans;

    for (vector<int> x : res)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    // return ans;
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