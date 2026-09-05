#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define CODEGOD                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void insertBTree(TreeNode *&root, int val)
{

    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }
    else
    {
        if (val < root->val)
        {
            insertBTree(root->left, val);
        }
        else if (val > root->val)
        {
            insertBTree(root->right, val);
        }
    }
}
vector<vector<int>> res;

void printLevelOrder(TreeNode *root)
{

    queue<TreeNode *> q;
    if (root != nullptr)
    {
        q.push(root);
    }
    else
        return;

    while (!q.empty())
    {
        int len = q.size();
        vector<int> layer;

        for (int i = 0; i < len; i++)
        {
            TreeNode *curr = q.front();
            layer.push_back(curr->val);
            q.pop();

            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        res.push_back(layer);
        /* code */
    }

    for (auto x : res)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
    }
}
void solve()
{
    int n;
    cin >> n;

    TreeNode *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertBTree(root, x);
    }

    printLevelOrder(root);
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