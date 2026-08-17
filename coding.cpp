#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve()
{
    int target;
    vector<int> nums;

    int n;
    cin >> n;
    cin >> target;
    int minimal = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
        int len = nums.size();

    int left = 0, right = 0;
    int sum = 0;

    while (right < len)
    {
        

        while (sum < target && right < len)
        {
            sum += nums[right];
            // cout<<sum<<" ";
            right++;
        }

        if (sum >= target)
        {
            minimal = min(minimal, right - left);
        }

        while (sum >= target && left <= right)
        {
            sum -= nums[left];
            left++;
            if (sum >= target)
            {
                minimal = min(minimal, right - left);
            }
        }
    }
    cout << (minimal == INT_MAX ? 0 : minimal) << endl;
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