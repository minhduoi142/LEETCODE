#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

int solve()
{
    vector<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int target;
    cin >> target;

    int len = nums.size();

    int l = 0;
    int r = len - 1;

    while (l <= r)
    {

        int mid = (l + r) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[l] < nums[mid])
        {
            if (target <= nums[mid] && target >= nums[l])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (target >= nums[mid] && target <= nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        /* code */
    }
    return -1;
}

signed main()
{
    CODEGOD;
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        /* code */
        cout << solve();
    }
}