#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int res = 0;

void backtrack(vector<int> &nums, int index, int curr, int target)
{

    if (index == nums.size())
    {
        if (curr == target)
        {
            res++;
        }
        return;
    }

    backtrack(nums, index + 1, curr + nums[index], target);
    backtrack(nums, index + 1, curr - nums[index], target);
}

void solve()
{

    vector<int> nums;
    int target;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cin >> target;

    backtrack(nums, 0, 0, target);

    cout << res;
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